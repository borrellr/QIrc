/****************************************************************************
** Form interface generated from reading ui file 'xircform.ui'
**
** Created: Sat Sep 3 17:18:51 2022
**      by: The User Interface Compiler ($Id: qt/main.cpp   3.3.3   edited Nov 24 2003 $)
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#ifndef XIRCFORM_H
#define XIRCFORM_H

#include <qvariant.h>
#include <qwidget.h>

class QVBoxLayout;
class QHBoxLayout;
class QGridLayout;
class QSpacerItem;
class QTextBrowser;
class QLineEdit;

class xIrcForm : public QWidget
{
    Q_OBJECT

public:
    xIrcForm( QWidget* parent = 0, const char* name = 0, WFlags fl = 0 );
    ~xIrcForm();

    QTextBrowser* Display;
    QLineEdit* lineEdit1;

protected:
    QVBoxLayout* xIrcFormLayout;

protected slots:
    virtual void languageChange();

};

#endif // XIRCFORM_H
