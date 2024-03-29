#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <qmainwindow.h>
#include <qstring.h>
#include "xircform.h"
#include "xIrcDefaults.h"
#include "xIrcQuitDialog.h"
#include "nicknameform.h"

class QAction;

class MainWindow : public QMainWindow
{
  Q_OBJECT
public:
  MainWindow(QWidget *parent = 0, const char *name = 0);

private slots:
  void about();
  void connectIRCsrvr();
  void openChannel();
  void showFolksOnline();
  void action();
  void changeNick();
  void serverList();
  void ignoreList();
  void notifyList();
  void xIrcQuit();

private:
  void createActions();
  void createMenus();
  void createToolBars();
  void createStatusBar();
  void createDialogs();
  void readSettings();
  void writeSettings();

  bool chkNickName();
  void setNickName();
  QString *nickName;

  xIrcForm *mainForm;
  QString *serverName;
  int port;

  QPopupMenu *fileMenu;
  QPopupMenu *nickMenu;
  QPopupMenu *listsMenu;
  QPopupMenu *helpMenu;

  QAction *connectAct;
  QAction *openAct;
  QAction *exitAct;

  QAction *showAct;
  QAction *actionAct;
  QAction *changeNickAct;

  QAction *serverListAct;
  QAction *ignoreListAct;
  QAction *notifyListAct;

  QAction *aboutAct;
  QAction *aboutQtAct;

  xIrcDefaults Defaults;
  xIrcQuitDialog *quitDialog;
  QString quitMsg;

  nickNameDialog *nickDialog;
  QString currNickName;
};

#endif
