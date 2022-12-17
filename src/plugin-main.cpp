/*
Plugin Name
Copyright (C) <Year> <Developer> <Email Address>

This program is free software; you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation; either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License along
with this program. If not, see <https://www.gnu.org/licenses/>
*/

#include <obs-module.h>
#include <obs-frontend-api.h>
#include <ui_toolbardock.h>
#include <plugin-main.h>
#include <QMainWindow>
#include "plugin-macros.generated.h"
#include <QPushButton>
#include <QMessageBox>
#include <util/platform.h>
#include <QTimer>

// #include "window-basic-main.hpp"
// #include <window-basic-settings.hpp>

OBS_DECLARE_MODULE()
OBS_MODULE_USE_DEFAULT_LOCALE(PLUGIN_NAME, "en-US")

bool obs_module_load(void)
{
	blog(LOG_INFO, "plugin loaded successfully (version %s)",
	     PLUGIN_VERSION);
	const auto main_window =
		static_cast<QMainWindow *>(obs_frontend_get_main_window());
	obs_frontend_push_ui_translation(obs_module_get_string);

	toolbarDock *dock = new toolbarDock(main_window);
	// dock->obs_basic = static_cast<OBSBasic *>(main_window);

#ifdef __APPLE__
	// #include <apple-window.mm>

	// extern "C" void changeTitleBarColor(WId winId, double red, double green, double blue, double alpha);

	// changeTitleBarColor(main_window->winId(), .5, .5, .5 , 1.0)
#endif

	obs_frontend_add_dock(dock);
	return true;
}

auto cpuUsage = os_cpu_usage_info_start();

void obs_module_unload()
{
	blog(LOG_INFO, "plugin unloaded");
}

MODULE_EXPORT const char *obs_module_description(void)
{
	return obs_module_text("Toolbar");
}

MODULE_EXPORT const char *obs_module_name(void)
{
	return obs_module_text("Toolbar");
}

#define QT_UTF8(str) QString::fromUtf8(str)
#define QT_TO_UTF8(str) str.toUtf8().constData()

/* Define the OBS Listener */
void obsEventDidFire(obs_frontend_event event, void *object);

toolbarDock::toolbarDock(QWidget *parent)
	: QDockWidget(parent, Qt::Window), ui(new Ui::toolbarDock)
{
	ui->setupUi(this);
	titlebar = this->titleBarWidget();

	this->configureStatus();
	this->checkDock();
	this->checkStudio();
	this->checkRecordingStatus();
	this->checkStreamingStatus();
	this->checkVirtualCamera();

	// this->addAction(ui->actionDisplay);
	// ui->actionDisplay->connect(ui->actionDisplay, SIGNAL( toggled(bool) ), this, SLOT( setIconMode(bool) ) );
	// connect( ui->actionDisplay, SIGNAL( QAction::triggered(bool) ), this, SLOT( setIconMode(bool) ) );

	ui->toolbarContents->installEventFilter(this);

	connect(ui->floatButton, SIGNAL(clicked()), this, SLOT(floatToolbar()));
	connect(ui->streamButton, SIGNAL(clicked()), this,
		SLOT(toggleStream()));
	connect(ui->recordButton, SIGNAL(clicked()), this,
		SLOT(toggleRecording()));
	connect(ui->modeSwitch, SIGNAL(clicked()), this, SLOT(toggleStudio()));
	connect(ui->virtualCamButton, SIGNAL(clicked()), this,
		SLOT(toggleCapture()));
	/*...*/
	// connect( ui->settingsButton, SIGNAL( clicked() ), this, SLOT( openSettings() ) );

	connect(this, SIGNAL(topLevelChanged(bool)), this, SLOT(checkDock()));
	connect(this, SIGNAL(featuresChanged(QDockWidget::DockWidgetFeatures)),
		this, SLOT(checkDock()));

	updateTimer = new QTimer(this);
	connect(updateTimer, SIGNAL(timeout()), this, SLOT(registerUpdate()));
	updateTimer->start(1000);

	obs_frontend_add_event_callback(obsEventDidFire, this);

	checkScene();
}

toolbarDock::~toolbarDock()
{
	updateTimer->stop();
	os_cpu_usage_info_destroy(cpuUsage);
	delete ui;
}

bool toolbarDock::eventFilter(QObject *object, QEvent *event)
{
	// auto label = qobject_cast<QLabel *>(object);
	// if ((label != nullptr) && (event->type() == QEvent::Resize)) {
	// 	// auto elidedName = ui->statusSceneName->fontMetrics().elidedText(QString(sceneName).trimmed(), Qt::TextElideMode::ElideRight, 128, 0);
	// 	auto elidedText = label->fontMetrics().elidedText(label->text(), Qt::TextElideMode::ElideRight, (label->width() > 100 ? 100 : label->width()), 0);
	// 	label->setText(elidedText);
	// 	return true;
	// } else {
	// 	return false;
	// }
	UNUSED_PARAMETER(object);

	if (event->type() == QEvent::Resize) {
		if (ui->toolbarContents->width() < 1280) {
			ui->toolbarControlFiller->setMinimumWidth(0);
		} else {
			ui->toolbarControlFiller->setMinimumWidth(46);
		}

		return true;
	} else {
		return false;
	}
}

void toolbarDock::configureStatus()
{
	// auto labels = ui->toolbarDisplay->findChildren<QLabel *>();

	// for (qsizetype i = 0; i < labels.count(); i++)
	// {
	// 	auto label = labels[i];
	// 	auto themeID = label->property("themeID");

	// 	if (themeID.isValid())
	// 	{
	// 		if (themeID.toString() == QString("toolbarStatusLabel"))
	// 		{
	// 			// label->installEventFilter(this);

	// 			// auto elidedText = label->fontMetrics().elidedText(label->text(), Qt::TextElideMode::ElideRight, 96, 0);
	// 			// label->setText(elidedText);
	// 			// label->setMinimumWidth(label->width());
	// 		}
	// 	}

	// }
}

void toolbarDock::floatToolbar()
{
	this->checkDock();
	this->setFloating(isDocked);
}

void toolbarDock::checkDock()
{
	isDocked = !(this->isFloating());
	isLocked = (this->features() == DockWidgetFeature::NoDockWidgetFeatures)
			   ? true
			   : false;

	if (isLocked) {
		ui->toolbarDockControls->hide();
		ui->toolbarControlFiller->setMaximumWidth(96);
	} else {
		ui->toolbarDockControls->show();
		ui->toolbarControlFiller->setMaximumWidth(46);
	}

	if (isDocked) {
		this->setTitleBarWidget(new QWidget());
	} else {
		this->setTitleBarWidget(titlebar);
	}
}

void toolbarDock::checkStudio()
{
	isInStudio = obs_frontend_preview_program_mode_active();

	ui->modeSwitch->setChecked(isInStudio);
}

void toolbarDock::checkRecordingStatus()
{
	isRecording = obs_frontend_recording_active();

	ui->recordButton->setChecked(isRecording);

	QString tooltext = QCoreApplication::translate(
		"toolbarDock", "Basic.Main.StartRecording", nullptr);
	QString statusText = QCoreApplication::translate(
		"toolbarDock", "Basic.Stats.Status.Inactive", nullptr);

	if (isRecording) {
		tooltext = QCoreApplication::translate(
			"toolbarDock", "Basic.Main.StopRecording", nullptr);
		statusText = QCoreApplication::translate(
			"toolbarDock", "Basic.Stats.Status.Active", nullptr);
	} else {
		recordingTime = QTime(0, 0);
	}

	ui->recordButton->setToolTip(tooltext);
	ui->recordButton->setAccessibleName(tooltext);

	ui->statusRecordStatus->setText(statusText);
}

void toolbarDock::checkStreamingStatus(bool inTransition, bool transitionState)
{
	isStreaming = obs_frontend_streaming_active();
	ui->streamButton->setChecked(isStreaming);

	QString tooltext = QCoreApplication::translate(
		"toolbarDock", "Basic.Main.StartStreaming", nullptr);
	QString statusText = QCoreApplication::translate(
		"toolbarDock", "Basic.Stats.Status.Inactive", nullptr);

	if (!inTransition) {
		if (isStreaming) {
			tooltext = QCoreApplication::translate(
				"toolbarDock", "Basic.Main.StopStreaming",
				nullptr);
		} else {
			streamingTime = QTime(0, 0);
			ui->statusStreamStatus->setText(statusText);
		}
	} else {
		if (transitionState) {
			tooltext = QCoreApplication::translate(
				"toolbarDock", "Basic.Main.Connecting",
				nullptr);
			statusText = QCoreApplication::translate(
				"toolbarDock", "Basic.Main.Connecting",
				nullptr);
		} else {
			tooltext = QCoreApplication::translate(
				"toolbarDock", "Basic.Main.StoppingStreaming",
				nullptr);
			statusText = QCoreApplication::translate(
				"toolbarDock", "Basic.Main.StoppingStreaming",
				nullptr);
		}

		ui->statusStreamStatus->setText(statusText);
	}

	ui->streamButton->setText(tooltext);
	ui->streamButton->setToolTip(tooltext);
	ui->streamButton->setAccessibleName(tooltext);
}

void toolbarDock::checkVirtualCamera()
{
	virtuallyCaptured = obs_frontend_virtualcam_active();

	ui->virtualCamButton->setChecked(virtuallyCaptured);

	QString tooltext = QCoreApplication::translate(
		"toolbarDock", "Basic.Main.StartVirtualCam", nullptr);

	if (virtuallyCaptured) {
		tooltext = QCoreApplication::translate(
			"toolbarDock", "Basic.Main.StopVirtualCam", nullptr);
	}

	ui->virtualCamButton->setToolTip(tooltext);
	ui->virtualCamButton->setAccessibleName(tooltext);
}

void toolbarDock::checkScene()
{
	auto scene = obs_frontend_get_current_scene();
	auto sceneName = obs_source_get_name(scene);

	// auto whitespace = " \r\n\t\v\f";
	// sceneName = sceneName.erase(0, sceneName.find_first_not_of(whitespace));

	auto elidedName = ui->statusSceneName->fontMetrics().elidedText(
		QString(sceneName).trimmed(), Qt::TextElideMode::ElideRight,
		128, 0);

	ui->statusSceneName->setText(elidedName);
}

void toolbarDock::toggleStudio()
{
	obs_frontend_set_preview_program_mode(
		!obs_frontend_preview_program_mode_active());
}

void toolbarDock::toggleStream()
{
	if (this->isStreaming) {
		QMessageBox confirmStreamAlert;
		confirmStreamAlert.setText(QCoreApplication::translate(
			"toolbarDock", "ConfirmStop.Text", nullptr));
		confirmStreamAlert.setStandardButtons(QMessageBox::Yes |
						      QMessageBox::No);
		confirmStreamAlert.setIcon(QMessageBox::Question);
		confirmStreamAlert.setDefaultButton(QMessageBox::No);
		int result = confirmStreamAlert.exec();

		switch (result) {
		case QMessageBox::No:
			checkStreamingStatus();
			break;
		case QMessageBox::Yes:
			obs_frontend_streaming_stop();
			break;
		}
	} else {
		QMessageBox confirmStreamAlert;
		confirmStreamAlert.setText(QCoreApplication::translate(
			"toolbarDock", "ConfirmStart.Text", nullptr));
		confirmStreamAlert.setStandardButtons(QMessageBox::Yes |
						      QMessageBox::No);
		confirmStreamAlert.setIcon(QMessageBox::Question);
		confirmStreamAlert.setDefaultButton(QMessageBox::No);
		int result = confirmStreamAlert.exec();

		switch (result) {
		case QMessageBox::No:
			checkStreamingStatus();
			break;
		case QMessageBox::Yes:
			obs_frontend_streaming_start();
			break;
		}
	}
}

void toolbarDock::toggleRecording()
{
	if (this->isRecording) {
		QMessageBox confirmStreamAlert;
		confirmStreamAlert.setText(QCoreApplication::translate(
			"toolbarDock", "ConfirmStopRecord.Text", nullptr));
		confirmStreamAlert.setStandardButtons(QMessageBox::Yes |
						      QMessageBox::No);
		confirmStreamAlert.setIcon(QMessageBox::Question);
		confirmStreamAlert.setDefaultButton(QMessageBox::No);
		int result = confirmStreamAlert.exec();

		switch (result) {
		case QMessageBox::No:
			checkRecordingStatus();
			break;
		case QMessageBox::Yes:
			obs_frontend_recording_stop();
			break;
		}
	} else {
		obs_frontend_recording_start();
	}
}

void toolbarDock::toggleCapture()
{
	if (this->virtuallyCaptured) {
		obs_frontend_stop_virtualcam();
	} else {
		obs_frontend_start_virtualcam();
	}
}

void toolbarDock::openSettings()
{
	// obs_basic->triggerSettings();
}

void toolbarDock::openVirtualCameraSettings() {}

void toolbarDock::setIconMode(bool useIcons)
{
	if (useIcons) {
		ui->streamButton->setToolButtonStyle(
			Qt::ToolButtonStyle::ToolButtonIconOnly);
		ui->modeSwitch->setToolButtonStyle(
			Qt::ToolButtonStyle::ToolButtonIconOnly);
	} else {
		ui->streamButton->setToolButtonStyle(
			Qt::ToolButtonStyle::ToolButtonTextOnly);
		ui->modeSwitch->setToolButtonStyle(
			Qt::ToolButtonStyle::ToolButtonTextOnly);
	}
	ui->streamButton->repaint();
	ui->modeSwitch->repaint();
}

void toolbarDock::registerUpdate()
{
	ui->statusCPUUsage->setText(
		QString::number((os_cpu_usage_info_query(cpuUsage)), (char)102,
				1)
			.append("%"));

	if (this->isStreaming) {
		streamingTime = streamingTime.addSecs(1);
		auto displayText =
			QCoreApplication::translate("toolbarDock",
						    "Basic.Stats.Status.Live",
						    nullptr)
				.append(" ")
				.append(streamingTime.toString("hh:mm:ss"));
		ui->statusStreamStatus->setText(displayText);
	}

	if (this->isRecording) {
		recordingTime = recordingTime.addSecs(1);
		ui->statusRecordStatus->setText(
			recordingTime.toString("hh:mm:ss"));
	}
}

// void toolbarDock::registerUpdate() {
// 	latestUpdate.setTimeout([&]() {
// 		auto cpuUsage = os_cpu_usage_info_start();
// 		QString cpuUsageInfo = QString("%1%").arg(os_cpu_usage_info_query(cpuUsage));
// 		ui->statusCPUUsage->setText(cpuUsageInfo);
// 	}, 2500);
// }

// void toolbarDock::registerActivity(bool stop) {
// 	if (stop && !isStreaming && !isRecording) {
// 		activeUpdate.stop();
// 	} else {
// 		latestUpdate.setTimeout([&]() {

// 				if (this->isStreaming)
// 				{
// 					this->streamTimeInSeconds++;
// 				}

// 				if (this->isRecording)
// 				{
// 					this->recordTimeInSeconds++;
// 				}

// 			}, 1000);
// 	}
// }

void obsEventDidFire(obs_frontend_event event, void *object)
{
	switch (event) {
	case OBS_FRONTEND_EVENT_STREAMING_STARTED:
		((toolbarDock *)object)->checkStreamingStatus();
		break;
	case OBS_FRONTEND_EVENT_STREAMING_STOPPED:
		((toolbarDock *)object)->checkStreamingStatus();
		break;
	case OBS_FRONTEND_EVENT_STREAMING_STARTING:
		((toolbarDock *)object)->checkStreamingStatus(true, true);
		break;
	case OBS_FRONTEND_EVENT_STREAMING_STOPPING:
		((toolbarDock *)object)->checkStreamingStatus(true);
		break;
	case OBS_FRONTEND_EVENT_STUDIO_MODE_ENABLED:
		((toolbarDock *)object)->checkStudio();
		break;
	case OBS_FRONTEND_EVENT_STUDIO_MODE_DISABLED:
		((toolbarDock *)object)->checkStudio();
		break;
	case OBS_FRONTEND_EVENT_RECORDING_STARTED:
		((toolbarDock *)object)->checkRecordingStatus();
		break;
	case OBS_FRONTEND_EVENT_RECORDING_STOPPED:
		((toolbarDock *)object)->checkRecordingStatus();
		break;
	case OBS_FRONTEND_EVENT_VIRTUALCAM_STARTED:
		((toolbarDock *)object)->checkVirtualCamera();
		break;
	case OBS_FRONTEND_EVENT_VIRTUALCAM_STOPPED:
		((toolbarDock *)object)->checkVirtualCamera();
		break;
	case OBS_FRONTEND_EVENT_SCENE_CHANGED:
		((toolbarDock *)object)->checkScene();
		break;
	default:
		break;
	}
}

// void toolbarDock::undoCommand() {

// }

// void toolbarDock::redoCommand() {

// }