/****************************************************************************
** Form interface generated from reading ui file 'quitform.ui'
**
** Created: Wed Oct 5 14:17:44 2022
**      by: The User Interface Compiler ($Id: qt/main.cpp   3.3.3   edited Nov 24 2003 $)
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#ifndef QUITDIALOG_H
#define QUITDIALOG_H

#include <qvariant.h>
#include <qdialog.h>

class QVBoxLayout;
class QHBoxLayout;
class QGridLayout;
class QSpacerItem;
class QLabel;
class QLineEdit;
class QPushButton;

class quitDialog : public QDialog
{
    Q_OBJECT

public:
    quitDialog( QWidget* parent = 0, const char* name = 0, bool modal = FALSE, WFlags fl = 0 );
    ~quitDialog();

    QLabel* textLabel1;
    QLineEdit* quitLineEdit;
    QPushButton* okButton;
    QPushButton* cancelButton;
    QPushButton* clearButton;
    QPushButton* defaultButton;

public slots:
    virtual void clearMsg();
    virtual void enableOkButton( const QString & str );

protected:
    QVBoxLayout* layout4;
    QHBoxLayout* layout3;
    QSpacerItem* spacer1;
    QHBoxLayout* layout1;

protected slots:
    virtual void languageChange();

};

#endif // QUITDIALOG_H
