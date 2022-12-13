/********************************************************************************
** Form generated from reading UI file 'toolbardockVQalbe.ui'
**
** Created by: Qt User Interface Compiler version 6.4.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef TOOLBARDOCKVQALBE_H
#define TOOLBARDOCKVQALBE_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDockWidget>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_toolbarDock {
public:
	QWidget *toolbarContents;
	QHBoxLayout *horizontalLayout;
	QWidget *toolbarDockControls;
	QHBoxLayout *horizontalLayout_3;
	QToolButton *floatButton;
	QSpacerItem *Spacer_Float;
	QToolButton *modeSwitch;
	QSpacerItem *Spacer_Filler;
	QWidget *toolbarControlFiller;
	QSpacerItem *Spacer_Center2;
	QFrame *toolbarDisplay;
	QHBoxLayout *horizontalLayout_2;
	QSpacerItem *PaneSpacer_Left;
	QLabel *statusStreamLabel;
	QLabel *panelColon;
	QLabel *statusStreamStatus;
	QLabel *HLine_1;
	QLabel *statusRecordLabel;
	QLabel *panelColon_2;
	QLabel *statusRecordStatus;
	QLabel *HLine_2;
	QLabel *statusSceneLabel;
	QLabel *panelColon_3;
	QLabel *statusSceneName;
	QLabel *HLine_3;
	QLabel *statusCPULabel;
	QLabel *statusCPUUsage;
	QSpacerItem *PaneSpacer_Right;
	QSpacerItem *Spacer_Center;
	QToolButton *virtualCamButton;
	QSpacerItem *Spacer_VirtualCam;
	QToolButton *recordButton;
	QSpacerItem *Spacer_Live;
	QToolButton *streamButton;

	void setupUi(QDockWidget *toolbarDock)
	{
		if (toolbarDock->objectName().isEmpty())
			toolbarDock->setObjectName("toolbarDock");
		toolbarDock->resize(1366, 52);
		QSizePolicy sizePolicy(QSizePolicy::Expanding,
				       QSizePolicy::MinimumExpanding);
		sizePolicy.setHorizontalStretch(0);
		sizePolicy.setVerticalStretch(0);
		sizePolicy.setHeightForWidth(
			toolbarDock->sizePolicy().hasHeightForWidth());
		toolbarDock->setSizePolicy(sizePolicy);
		toolbarDock->setMinimumSize(QSize(1282, 52));
		toolbarDock->setMaximumSize(QSize(524287, 54));
		toolbarDock->setContextMenuPolicy(Qt::ActionsContextMenu);
		toolbarDock->setStyleSheet(QString::fromUtf8(
			"#toolbarDock  {\n"
			"min-width: 1280px;\n"
			"max-height: 52px;\n"
			"padding: 0px;\n"
			"}\n"
			"\n"
			"#toolbarDock QToolButton {\n"
			"min-height: 32px;\n"
			"max-height: 32px;\n"
			"padding: 0px;\n"
			"}\n"
			"\n"
			"#toolbarDock *[themeID=\"toolbarSpace\"] {\n"
			"opacity: 0;\n"
			"background-color: transparent;\n"
			"}\n"
			"\n"
			"#toolbarDockControls {\n"
			"background-color: transparent;\n"
			"}\n"
			"\n"
			"#toolbarDock QToolButton[toolButtonStyle=\"ToolButtonIconOnly\"] {\n"
			"min-width: 32px;\n"
			"max-width: 32px;\n"
			"}\n"
			"\n"
			"#toolbarDock QToolButton[toolButtonStyle=\"ToolButtonTextOnly\"] {\n"
			"min-width: 128px;\n"
			"max-width: 192px;\n"
			"}"));
		toolbarDock->setFeatures(QDockWidget::DockWidgetClosable |
					 QDockWidget::DockWidgetFloatable |
					 QDockWidget::DockWidgetMovable);
		toolbarDock->setAllowedAreas(Qt::BottomDockWidgetArea |
					     Qt::TopDockWidgetArea);
		toolbarContents = new QWidget();
		toolbarContents->setObjectName("toolbarContents");
		sizePolicy.setHeightForWidth(
			toolbarContents->sizePolicy().hasHeightForWidth());
		toolbarContents->setSizePolicy(sizePolicy);
		toolbarContents->setMinimumSize(QSize(0, 30));
		toolbarContents->setMaximumSize(QSize(16777215, 52));
		horizontalLayout = new QHBoxLayout(toolbarContents);
		horizontalLayout->setSpacing(4);
		horizontalLayout->setObjectName("horizontalLayout");
		horizontalLayout->setContentsMargins(16, 0, 16, 0);
		toolbarDockControls = new QWidget(toolbarContents);
		toolbarDockControls->setObjectName("toolbarDockControls");
		QSizePolicy sizePolicy1(QSizePolicy::Fixed,
					QSizePolicy::Preferred);
		sizePolicy1.setHorizontalStretch(0);
		sizePolicy1.setVerticalStretch(0);
		sizePolicy1.setHeightForWidth(
			toolbarDockControls->sizePolicy().hasHeightForWidth());
		toolbarDockControls->setSizePolicy(sizePolicy1);
		toolbarDockControls->setMinimumSize(QSize(46, 32));
		toolbarDockControls->setMaximumSize(QSize(46, 32));
		horizontalLayout_3 = new QHBoxLayout(toolbarDockControls);
		horizontalLayout_3->setSpacing(4);
		horizontalLayout_3->setObjectName("horizontalLayout_3");
		horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
		floatButton = new QToolButton(toolbarDockControls);
		floatButton->setObjectName("floatButton");
		QSizePolicy sizePolicy2(QSizePolicy::Fixed, QSizePolicy::Fixed);
		sizePolicy2.setHorizontalStretch(0);
		sizePolicy2.setVerticalStretch(0);
		sizePolicy2.setHeightForWidth(
			floatButton->sizePolicy().hasHeightForWidth());
		floatButton->setSizePolicy(sizePolicy2);
		floatButton->setMinimumSize(QSize(34, 34));
		floatButton->setMaximumSize(QSize(34, 34));
		floatButton->setAutoFillBackground(false);
		QIcon icon;
		icon.addFile(
			QString::fromUtf8(":/res/images/sources/window.svg"),
			QSize(), QIcon::Normal, QIcon::Off);
		floatButton->setIcon(icon);

		horizontalLayout_3->addWidget(floatButton, 0, Qt::AlignVCenter);

		Spacer_Float = new QSpacerItem(10, 20, QSizePolicy::Fixed,
					       QSizePolicy::Minimum);

		horizontalLayout_3->addItem(Spacer_Float);

		horizontalLayout->addWidget(toolbarDockControls, 0,
					    Qt::AlignVCenter);

		modeSwitch = new QToolButton(toolbarContents);
		modeSwitch->setObjectName("modeSwitch");
		QSizePolicy sizePolicy3(QSizePolicy::Expanding,
					QSizePolicy::Fixed);
		sizePolicy3.setHorizontalStretch(0);
		sizePolicy3.setVerticalStretch(0);
		sizePolicy3.setHeightForWidth(
			modeSwitch->sizePolicy().hasHeightForWidth());
		modeSwitch->setSizePolicy(sizePolicy3);
		modeSwitch->setMinimumSize(QSize(130, 34));
		modeSwitch->setMaximumSize(QSize(194, 34));
		modeSwitch->setAutoFillBackground(false);
		QIcon icon1;
		icon1.addFile(
			QString::fromUtf8(":/res/images/sources/slideshow.svg"),
			QSize(), QIcon::Normal, QIcon::Off);
		modeSwitch->setIcon(icon1);
		modeSwitch->setIconSize(QSize(20, 20));
		modeSwitch->setCheckable(true);
		modeSwitch->setToolButtonStyle(Qt::ToolButtonTextOnly);

		horizontalLayout->addWidget(modeSwitch);

		Spacer_Filler = new QSpacerItem(46, 20, QSizePolicy::Fixed,
						QSizePolicy::Minimum);

		horizontalLayout->addItem(Spacer_Filler);

		toolbarControlFiller = new QWidget(toolbarContents);
		toolbarControlFiller->setObjectName("toolbarControlFiller");
		toolbarControlFiller->setEnabled(true);
		sizePolicy1.setHeightForWidth(
			toolbarControlFiller->sizePolicy().hasHeightForWidth());
		toolbarControlFiller->setSizePolicy(sizePolicy1);
		toolbarControlFiller->setMinimumSize(QSize(46, 20));
		toolbarControlFiller->setMaximumSize(QSize(46, 20));

		horizontalLayout->addWidget(toolbarControlFiller);

		Spacer_Center2 = new QSpacerItem(10, 20,
						 QSizePolicy::MinimumExpanding,
						 QSizePolicy::Minimum);

		horizontalLayout->addItem(Spacer_Center2);

		toolbarDisplay = new QFrame(toolbarContents);
		toolbarDisplay->setObjectName("toolbarDisplay");
		QSizePolicy sizePolicy4(QSizePolicy::Maximum,
					QSizePolicy::Fixed);
		sizePolicy4.setHorizontalStretch(0);
		sizePolicy4.setVerticalStretch(0);
		sizePolicy4.setHeightForWidth(
			toolbarDisplay->sizePolicy().hasHeightForWidth());
		toolbarDisplay->setSizePolicy(sizePolicy4);
		toolbarDisplay->setMinimumSize(QSize(458, 30));
		toolbarDisplay->setMaximumSize(QSize(610, 30));
		toolbarDisplay->setAcceptDrops(false);
		toolbarDisplay->setAutoFillBackground(false);
		toolbarDisplay->setStyleSheet(QString::fromUtf8(
			"#toolbarDisplay {\n"
			"padding: 4px;\n"
			"min-width: 448px;\n"
			"max-width: 600px;\n"
			"}\n"
			"\n"
			"#toolbarDisplay QLabel[themeID=\"toolDIsplaySeparator\"] {\n"
			"color: rgba(127,127,127,0.5);\n"
			"font-weight: 800;\n"
			"margin: 0px 5px;\n"
			"}"));
		toolbarDisplay->setFrameShape(QFrame::StyledPanel);
		horizontalLayout_2 = new QHBoxLayout(toolbarDisplay);
		horizontalLayout_2->setSpacing(0);
		horizontalLayout_2->setObjectName("horizontalLayout_2");
		horizontalLayout_2->setContentsMargins(4, 0, 4, 0);
		PaneSpacer_Left = new QSpacerItem(10, 20,
						  QSizePolicy::MinimumExpanding,
						  QSizePolicy::Minimum);

		horizontalLayout_2->addItem(PaneSpacer_Left);

		statusStreamLabel = new QLabel(toolbarDisplay);
		statusStreamLabel->setObjectName("statusStreamLabel");
		statusStreamLabel->setEnabled(true);
		QSizePolicy sizePolicy5(QSizePolicy::Preferred,
					QSizePolicy::Preferred);
		sizePolicy5.setHorizontalStretch(0);
		sizePolicy5.setVerticalStretch(0);
		sizePolicy5.setHeightForWidth(
			statusStreamLabel->sizePolicy().hasHeightForWidth());
		statusStreamLabel->setSizePolicy(sizePolicy5);
		statusStreamLabel->setTextFormat(Qt::PlainText);
		statusStreamLabel->setScaledContents(false);
		statusStreamLabel->setTextInteractionFlags(
			Qt::NoTextInteraction);

		horizontalLayout_2->addWidget(statusStreamLabel);

		panelColon = new QLabel(toolbarDisplay);
		panelColon->setObjectName("panelColon");
		sizePolicy1.setHeightForWidth(
			panelColon->sizePolicy().hasHeightForWidth());
		panelColon->setSizePolicy(sizePolicy1);
		panelColon->setMinimumSize(QSize(8, 0));
		panelColon->setTextInteractionFlags(Qt::NoTextInteraction);

		horizontalLayout_2->addWidget(panelColon);

		statusStreamStatus = new QLabel(toolbarDisplay);
		statusStreamStatus->setObjectName("statusStreamStatus");
		sizePolicy5.setHeightForWidth(
			statusStreamStatus->sizePolicy().hasHeightForWidth());
		statusStreamStatus->setSizePolicy(sizePolicy5);
		statusStreamStatus->setTextFormat(Qt::PlainText);
		statusStreamStatus->setScaledContents(false);
		statusStreamStatus->setTextInteractionFlags(
			Qt::NoTextInteraction);

		horizontalLayout_2->addWidget(statusStreamStatus);

		HLine_1 = new QLabel(toolbarDisplay);
		HLine_1->setObjectName("HLine_1");
		sizePolicy1.setHeightForWidth(
			HLine_1->sizePolicy().hasHeightForWidth());
		HLine_1->setSizePolicy(sizePolicy1);
		HLine_1->setMinimumSize(QSize(12, 0));
		HLine_1->setText(QString::fromUtf8("\357\275\234"));
		HLine_1->setTextFormat(Qt::PlainText);
		HLine_1->setAlignment(Qt::AlignCenter);
		HLine_1->setTextInteractionFlags(Qt::NoTextInteraction);

		horizontalLayout_2->addWidget(HLine_1);

		statusRecordLabel = new QLabel(toolbarDisplay);
		statusRecordLabel->setObjectName("statusRecordLabel");
		sizePolicy5.setHeightForWidth(
			statusRecordLabel->sizePolicy().hasHeightForWidth());
		statusRecordLabel->setSizePolicy(sizePolicy5);
		statusRecordLabel->setMinimumSize(QSize(0, 0));
		statusRecordLabel->setTextFormat(Qt::PlainText);
		statusRecordLabel->setScaledContents(false);
		statusRecordLabel->setTextInteractionFlags(
			Qt::NoTextInteraction);

		horizontalLayout_2->addWidget(statusRecordLabel);

		panelColon_2 = new QLabel(toolbarDisplay);
		panelColon_2->setObjectName("panelColon_2");
		sizePolicy1.setHeightForWidth(
			panelColon_2->sizePolicy().hasHeightForWidth());
		panelColon_2->setSizePolicy(sizePolicy1);
		panelColon_2->setMinimumSize(QSize(8, 0));
		panelColon_2->setText(QString::fromUtf8(": "));
		panelColon_2->setTextInteractionFlags(Qt::NoTextInteraction);

		horizontalLayout_2->addWidget(panelColon_2);

		statusRecordStatus = new QLabel(toolbarDisplay);
		statusRecordStatus->setObjectName("statusRecordStatus");
		sizePolicy5.setHeightForWidth(
			statusRecordStatus->sizePolicy().hasHeightForWidth());
		statusRecordStatus->setSizePolicy(sizePolicy5);
		statusRecordStatus->setTextFormat(Qt::PlainText);
		statusRecordStatus->setScaledContents(false);
		statusRecordStatus->setTextInteractionFlags(
			Qt::NoTextInteraction);

		horizontalLayout_2->addWidget(statusRecordStatus);

		HLine_2 = new QLabel(toolbarDisplay);
		HLine_2->setObjectName("HLine_2");
		sizePolicy1.setHeightForWidth(
			HLine_2->sizePolicy().hasHeightForWidth());
		HLine_2->setSizePolicy(sizePolicy1);
		HLine_2->setMinimumSize(QSize(12, 0));
		HLine_2->setText(QString::fromUtf8("\357\275\234"));
		HLine_2->setAlignment(Qt::AlignCenter);
		HLine_2->setTextInteractionFlags(Qt::NoTextInteraction);

		horizontalLayout_2->addWidget(HLine_2);

		statusSceneLabel = new QLabel(toolbarDisplay);
		statusSceneLabel->setObjectName("statusSceneLabel");
		statusSceneLabel->setMinimumSize(QSize(0, 0));
		statusSceneLabel->setTextInteractionFlags(
			Qt::NoTextInteraction);

		horizontalLayout_2->addWidget(statusSceneLabel);

		panelColon_3 = new QLabel(toolbarDisplay);
		panelColon_3->setObjectName("panelColon_3");
		sizePolicy1.setHeightForWidth(
			panelColon_3->sizePolicy().hasHeightForWidth());
		panelColon_3->setSizePolicy(sizePolicy1);
		panelColon_3->setMinimumSize(QSize(8, 0));
		panelColon_3->setText(QString::fromUtf8(": "));
		panelColon_3->setTextInteractionFlags(Qt::NoTextInteraction);

		horizontalLayout_2->addWidget(panelColon_3);

		statusSceneName = new QLabel(toolbarDisplay);
		statusSceneName->setObjectName("statusSceneName");
		sizePolicy5.setHeightForWidth(
			statusSceneName->sizePolicy().hasHeightForWidth());
		statusSceneName->setSizePolicy(sizePolicy5);
		statusSceneName->setMaximumSize(QSize(128, 16777215));
		statusSceneName->setTextFormat(Qt::PlainText);
		statusSceneName->setTextInteractionFlags(Qt::NoTextInteraction);

		horizontalLayout_2->addWidget(statusSceneName, 0,
					      Qt::AlignVCenter);

		HLine_3 = new QLabel(toolbarDisplay);
		HLine_3->setObjectName("HLine_3");
		sizePolicy1.setHeightForWidth(
			HLine_3->sizePolicy().hasHeightForWidth());
		HLine_3->setSizePolicy(sizePolicy1);
		HLine_3->setMinimumSize(QSize(12, 0));
		HLine_3->setText(QString::fromUtf8("\357\275\234"));
		HLine_3->setTextFormat(Qt::PlainText);
		HLine_3->setTextInteractionFlags(Qt::NoTextInteraction);

		horizontalLayout_2->addWidget(HLine_3);

		statusCPULabel = new QLabel(toolbarDisplay);
		statusCPULabel->setObjectName("statusCPULabel");
		sizePolicy1.setHeightForWidth(
			statusCPULabel->sizePolicy().hasHeightForWidth());
		statusCPULabel->setSizePolicy(sizePolicy1);
		statusCPULabel->setMinimumSize(QSize(34, 0));
		statusCPULabel->setMaximumSize(QSize(34, 16777215));

		horizontalLayout_2->addWidget(statusCPULabel);

		statusCPUUsage = new QLabel(toolbarDisplay);
		statusCPUUsage->setObjectName("statusCPUUsage");

		horizontalLayout_2->addWidget(statusCPUUsage);

		PaneSpacer_Right =
			new QSpacerItem(10, 20, QSizePolicy::MinimumExpanding,
					QSizePolicy::Minimum);

		horizontalLayout_2->addItem(PaneSpacer_Right);

		horizontalLayout->addWidget(toolbarDisplay);

		Spacer_Center = new QSpacerItem(10, 20,
						QSizePolicy::MinimumExpanding,
						QSizePolicy::Minimum);

		horizontalLayout->addItem(Spacer_Center);

		virtualCamButton = new QToolButton(toolbarContents);
		virtualCamButton->setObjectName("virtualCamButton");
		sizePolicy2.setHeightForWidth(
			virtualCamButton->sizePolicy().hasHeightForWidth());
		virtualCamButton->setSizePolicy(sizePolicy2);
		virtualCamButton->setMinimumSize(QSize(34, 34));
		virtualCamButton->setMaximumSize(QSize(34, 34));
		virtualCamButton->setAutoFillBackground(false);
		QIcon icon2;
		icon2.addFile(
			QString::fromUtf8(":/res/Images/video-inactive.svg"),
			QSize(), QIcon::Normal, QIcon::Off);
		icon2.addFile(
			QString::fromUtf8(":/res/Images/video-active.svg"),
			QSize(), QIcon::Normal, QIcon::On);
		virtualCamButton->setIcon(icon2);
		virtualCamButton->setIconSize(QSize(20, 20));
		virtualCamButton->setCheckable(true);

		horizontalLayout->addWidget(virtualCamButton, 0,
					    Qt::AlignVCenter);

		Spacer_VirtualCam = new QSpacerItem(10, 20, QSizePolicy::Fixed,
						    QSizePolicy::Minimum);

		horizontalLayout->addItem(Spacer_VirtualCam);

		recordButton = new QToolButton(toolbarContents);
		recordButton->setObjectName("recordButton");
		sizePolicy2.setHeightForWidth(
			recordButton->sizePolicy().hasHeightForWidth());
		recordButton->setSizePolicy(sizePolicy2);
		recordButton->setMinimumSize(QSize(34, 34));
		recordButton->setMaximumSize(QSize(34, 34));
		recordButton->setAutoFillBackground(false);
		QIcon icon3;
		icon3.addFile(QString::fromUtf8(
				      ":/res/images/recording-inactive.svg"),
			      QSize(), QIcon::Normal, QIcon::Off);
		icon3.addFile(
			QString::fromUtf8(":/res/images/recording-active.svg"),
			QSize(), QIcon::Normal, QIcon::On);
		icon3.addFile(QString::fromUtf8(
				      ":/res/images/recording-inactive.svg"),
			      QSize(), QIcon::Disabled, QIcon::On);
		icon3.addFile(QString::fromUtf8(
				      ":/res/images/recording-inactive.svg"),
			      QSize(), QIcon::Active, QIcon::Off);
		icon3.addFile(QString::fromUtf8(
				      ":/res/images/recording-inactive.svg"),
			      QSize(), QIcon::Selected, QIcon::On);
		recordButton->setIcon(icon3);
		recordButton->setIconSize(QSize(20, 20));
		recordButton->setCheckable(true);

		horizontalLayout->addWidget(recordButton, 0, Qt::AlignVCenter);

		Spacer_Live = new QSpacerItem(10, 20, QSizePolicy::Fixed,
					      QSizePolicy::Minimum);

		horizontalLayout->addItem(Spacer_Live);

		streamButton = new QToolButton(toolbarContents);
		streamButton->setObjectName("streamButton");
		sizePolicy3.setHeightForWidth(
			streamButton->sizePolicy().hasHeightForWidth());
		streamButton->setSizePolicy(sizePolicy3);
		streamButton->setMinimumSize(QSize(130, 34));
		streamButton->setMaximumSize(QSize(194, 34));
		streamButton->setAutoFillBackground(false);
		QIcon icon4;
		icon4.addFile(QString::fromUtf8(
				      ":/res/images/streaming-inactive.svg"),
			      QSize(), QIcon::Normal, QIcon::Off);
		icon4.addFile(
			QString::fromUtf8(":/res/images/streaming-active.svg"),
			QSize(), QIcon::Normal, QIcon::On);
		icon4.addFile(QString::fromUtf8(
				      ":/res/images/streaming-inactive.svg"),
			      QSize(), QIcon::Disabled, QIcon::On);
		icon4.addFile(QString::fromUtf8(
				      ":/res/images/streaming-inactive.svg"),
			      QSize(), QIcon::Selected, QIcon::On);
		streamButton->setIcon(icon4);
		streamButton->setIconSize(QSize(20, 20));
		streamButton->setCheckable(true);
		streamButton->setToolButtonStyle(Qt::ToolButtonTextOnly);

		horizontalLayout->addWidget(streamButton, 0, Qt::AlignVCenter);

		toolbarDock->setWidget(toolbarContents);

		retranslateUi(toolbarDock);

		QMetaObject::connectSlotsByName(toolbarDock);
	} // setupUi

	void retranslateUi(QDockWidget *toolbarDock)
	{
		toolbarDock->setWindowTitle(QCoreApplication::translate(
			"toolbarDock", "Toolbar", nullptr));
#if QT_CONFIG(tooltip)
		floatButton->setToolTip(QCoreApplication::translate(
			"toolbarDock", "Dock/Undock", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(accessibility)
		floatButton->setAccessibleName(QCoreApplication::translate(
			"toolbarDock", "Dock/Undock", nullptr));
#endif // QT_CONFIG(accessibility)
		floatButton->setText(QString());
#if QT_CONFIG(tooltip)
		modeSwitch->setToolTip(QCoreApplication::translate(
			"toolbarDock", "Basic.TogglePreviewProgramMode",
			nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(accessibility)
		modeSwitch->setAccessibleName(QCoreApplication::translate(
			"toolbarDock", "Basic.TogglePreviewProgramMode",
			nullptr));
#endif // QT_CONFIG(accessibility)
		modeSwitch->setText(QCoreApplication::translate(
			"toolbarDock", "Basic.TogglePreviewProgramMode",
			nullptr));
		toolbarControlFiller->setProperty(
			"themeID",
			QVariant(QCoreApplication::translate(
				"toolbarDock", "toolbarSpace", nullptr)));
#if QT_CONFIG(accessibility)
		statusStreamLabel->setAccessibleName(
			QCoreApplication::translate(
				"toolbarDock", "Basic.Stats.Status", nullptr));
#endif // QT_CONFIG(accessibility)
		statusStreamLabel->setText(QCoreApplication::translate(
			"toolbarDock", "Basic.Stats.Status", nullptr));
		statusStreamLabel->setProperty(
			"themeID",
			QVariant(QCoreApplication::translate(
				"toolbarDock", "toolbarStatusLabel", nullptr)));
		panelColon->setText(QCoreApplication::translate("toolbarDock",
								": ", nullptr));
		statusStreamStatus->setText(QCoreApplication::translate(
			"toolbarDock", "Basic.Stats.Status.Inactive", nullptr));
		statusStreamStatus->setProperty(
			"themeID",
			QVariant(QCoreApplication::translate(
				"toolbarDock", "toolbarStatusText", nullptr)));
		HLine_1->setProperty("themeID",
				     QVariant(QCoreApplication::translate(
					     "toolbarDock",
					     "toolDIsplaySeparator", nullptr)));
		statusRecordLabel->setText(QCoreApplication::translate(
			"toolbarDock", "Basic.Stats.Output.Recording",
			nullptr));
		statusRecordLabel->setProperty(
			"themeID",
			QVariant(QCoreApplication::translate(
				"toolbarDock", "toolbarStatusLabel", nullptr)));
		statusRecordStatus->setText(QCoreApplication::translate(
			"toolbarDock", "Basic.Stats.Status.Inactive", nullptr));
		statusRecordStatus->setProperty(
			"themeID",
			QVariant(QCoreApplication::translate(
				"toolbarDock", "toolbarStatusText", nullptr)));
		HLine_2->setProperty("themeID",
				     QVariant(QCoreApplication::translate(
					     "toolbarDock",
					     "toolDIsplaySeparator", nullptr)));
		statusSceneLabel->setText(QCoreApplication::translate(
			"toolbarDock", "Basic.Scene", nullptr));
		statusSceneLabel->setProperty(
			"themeID",
			QVariant(QCoreApplication::translate(
				"toolbarDock", "toolbarStatusLabel", nullptr)));
		statusSceneName->setText(QCoreApplication::translate(
			"toolbarDock", "Basic.Scene", nullptr));
		statusSceneName->setProperty(
			"themeID",
			QVariant(QCoreApplication::translate(
				"toolbarDock", "toolbarStatusText", nullptr)));
		HLine_3->setProperty("themeID",
				     QVariant(QCoreApplication::translate(
					     "toolbarDock",
					     "toolDIsplaySeparator", nullptr)));
		statusCPULabel->setText(QCoreApplication::translate(
			"toolbarDock", "CPU: ", nullptr));
		statusCPULabel->setProperty(
			"themeID",
			QVariant(QCoreApplication::translate(
				"toolbarDock", "toolbarStatusLabel", nullptr)));
		statusCPUUsage->setText(QCoreApplication::translate(
			"toolbarDock", "%", nullptr));
		statusCPUUsage->setProperty(
			"themeID",
			QVariant(QCoreApplication::translate(
				"toolbarDock", "toolbarStatusText", nullptr)));
#if QT_CONFIG(tooltip)
		virtualCamButton->setToolTip(QCoreApplication::translate(
			"toolbarDock", "Basic.Main.StartVirtualCam", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(accessibility)
		virtualCamButton->setAccessibleName(QCoreApplication::translate(
			"toolbarDock", "Basic.Main.StartVirtualCam", nullptr));
#endif // QT_CONFIG(accessibility)
		virtualCamButton->setProperty(
			"themeID",
			QVariant(QCoreApplication::translate(
				"toolbarDock", "vcamButton", nullptr)));
#if QT_CONFIG(tooltip)
		recordButton->setToolTip(QCoreApplication::translate(
			"toolbarDock", "Basic.Main.StartRecording", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(accessibility)
		recordButton->setAccessibleName(QCoreApplication::translate(
			"toolbarDock", "Basic.Main.StartRecording", nullptr));
#endif // QT_CONFIG(accessibility)
#if QT_CONFIG(tooltip)
		streamButton->setToolTip(QCoreApplication::translate(
			"toolbarDock", "Basic.Main.StartStreaming", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(accessibility)
		streamButton->setAccessibleName(QCoreApplication::translate(
			"toolbarDock", "Basic.Main.StartStreaming", nullptr));
#endif // QT_CONFIG(accessibility)
		streamButton->setText(QCoreApplication::translate(
			"toolbarDock", "Basic.Main.StartStreaming", nullptr));
	} // retranslateUi
};

namespace Ui {
class toolbarDock : public Ui_toolbarDock {};
} // namespace Ui

QT_END_NAMESPACE

#endif // TOOLBARDOCKVQALBE_H
