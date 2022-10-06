#include <qaction.h>
#include <qapplication.h>
#include <qpopupmenu.h>
#include <qmenubar.h>
#include <qmessagebox.h>

#include "xircform.h"
#include "mainwindow.h"
#include "xIrcQuitDialog.h"

MainWindow::MainWindow(QWidget *parent, const char *name)
    : QMainWindow(parent, name)
{
  mainForm = new xIrcForm(this);
  setCentralWidget(mainForm);

  createActions();
  createMenus();
  createToolBars();
  createStatusBar();

  readSettings();

  setCaption("xIrc");

  quitDialog = new xIrcQuitDialog(Defaults);
}

void MainWindow::createActions()
{
  connectAct = new QAction(tr("&Connect"), tr("Ctrl-C"), this);
  connectAct->setStatusTip(tr("Connect to Irc Server"));
  connect(connectAct, SIGNAL(activated()), this, SLOT(connectIRCsrvr()));

  openAct = new QAction(tr("&Open Channel"), tr("Ctrl-O"), this);
  openAct->setStatusTip(tr("Open Channel"));
  connect(openAct, SIGNAL(activated()), this, SLOT(openChannel()));

  exitAct = new QAction(tr("E&xit"), tr("Ctrl-Q"), this);
  exitAct->setStatusTip(tr("Exit xIrc"));
  connect(exitAct, SIGNAL(activated()), this, SLOT(xIrcQuit()));

  showAct = new QAction(tr("Show Folks Online"), 0, this);
  showAct->setStatusTip(tr("Show Folks Online"));
  connect(showAct, SIGNAL(activated()), this, SLOT(showFolksOnline()));

  actionAct = new QAction(tr("Action"), 0, this);
  connect(actionAct, SIGNAL(activated()), this, SLOT(action()));

  changeNickAct = new QAction(tr("Change Nick"), 0, this);
  changeNickAct->setStatusTip(tr("Change Nick"));
  connect(changeNickAct, SIGNAL(activated()), this, SLOT(changeNick()));

  serverListAct = new QAction(tr("Server List"), 0, this);
  serverListAct->setStatusTip(tr("Server List"));
  connect(serverListAct, SIGNAL(activated()), this, SLOT(serverList()));

  ignoreListAct = new QAction(tr("Ignore List"), 0, this);
  ignoreListAct->setStatusTip(tr("Ignore List"));
  connect(ignoreListAct, SIGNAL(activated()), this, SLOT(ignoreList()));

  notifyListAct = new QAction(tr("Notify List"), 0, this);
  notifyListAct->setStatusTip(tr("Notify List"));
  connect(notifyListAct, SIGNAL(activated()), this, SLOT(notifyList()));

  aboutAct = new QAction(tr("About xIrc"), 0, this);
  aboutAct->setStatusTip(tr("Show xIrc Information"));
  connect(aboutAct, SIGNAL(activated()), this, SLOT(about()));

  aboutQtAct = new QAction(tr("About &Qt"), 0, this);
  aboutQtAct->setStatusTip(tr("Show the Qt library's about box"));
  connect(aboutQtAct, SIGNAL(activated()), qApp, SLOT(aboutQt()));
}

void MainWindow::createMenus()
{
  fileMenu = new QPopupMenu(this);
  connectAct->addTo(fileMenu);
  openAct->addTo(fileMenu);
  fileMenu->insertSeparator();
  exitAct->addTo(fileMenu);

  nickMenu = new QPopupMenu(this);
  showAct->addTo(nickMenu);
  actionAct->addTo(nickMenu);
  changeNickAct->addTo(nickMenu); 

  listsMenu = new QPopupMenu(this);
  serverListAct->addTo(listsMenu);
  ignoreListAct->addTo(listsMenu);
  notifyListAct->addTo(listsMenu);

  helpMenu = new QPopupMenu(this);
  aboutAct->addTo(helpMenu);
  aboutQtAct->addTo(helpMenu);

  menuBar()->insertItem(tr("&File"), fileMenu);
  menuBar()->insertItem(tr("Nick"), nickMenu);
  menuBar()->insertItem(tr("Lists"), listsMenu);
  menuBar()->insertSeparator();
  menuBar()->insertItem(tr("&Help"), helpMenu);
}

void MainWindow::createToolBars()
{
}

void MainWindow::createStatusBar()
{
}

void MainWindow::readSettings()
{
  Defaults.load();
}

void MainWindow::writeSettings()
{
}

void MainWindow::about()
{
    QMessageBox::about(this, tr("About xIrc"),
            tr("<h2>xIrc 3.0</h2>"
               "<p>License: GPL"
               "<p>Copyright &copy 1996-2022 by Robert Borrell"
               "<p>Created by Joe Croft"));
}

void MainWindow::connectIRCsrvr()
{
}

void MainWindow::openChannel()
{
}

void MainWindow::showFolksOnline()
{
}

void MainWindow::action()
{
}

void MainWindow::changeNick()
{
}

void MainWindow::serverList()
{
}

void MainWindow::ignoreList()
{
}

void MainWindow::notifyList()
{
}

void MainWindow::xIrcQuit()
{
   quitDialog->show();
   quitDialog->raise();
   quitDialog->setActiveWindow();
   if (quitDialog->exec() != QDialog::Rejected) {
      qApp->quit();
   }
}
