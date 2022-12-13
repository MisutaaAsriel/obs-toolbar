#pragma once
#include "obs.h"
#include <obs-frontend-api.h>
#include <QDockWidget>
#include "obs.hpp"
// #include <obs-basic-stub.h>
#include <QTimer>
#include <QTime>

namespace Ui {
class toolbarDock;
}

class toolbarDock : public QDockWidget {
	Q_OBJECT

public:
	explicit toolbarDock(QWidget *parent = nullptr);
	~toolbarDock();
	// OBSBasic *obs_basic;
	void checkRecordingStatus();
	void checkStreamingStatus(bool inTransition = false,
				  bool transitionState = false);
	void checkVirtualCamera();
	void checkStudio();
	void checkScene();
	QTime recordingTime = QTime(0, 0);
	QTime streamingTime = QTime(0, 0);
	QTimer *updateTimer;

public slots:
	void checkDock();

private:
	Ui::toolbarDock *ui{};
	QWidget *titlebar;
	bool isDocked;
	bool isLocked;
	bool isInStudio;
	bool isStreaming = false;
	bool isRecording = false;
	bool virtuallyCaptured;

private slots:
	void configureStatus();
	void floatToolbar();
	void toggleStudio();
	void toggleStream();
	void toggleRecording();
	void toggleCapture();
	void openSettings();
	void openVirtualCameraSettings();
	void setIconMode(bool useIcons);
	void registerUpdate();
	// void undoCommand();
	// void redoCommand();

protected:
	bool eventFilter(QObject *obj, QEvent *event) override;
};