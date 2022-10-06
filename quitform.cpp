/****************************************************************************
** Form implementation generated from reading ui file 'quitform.ui'
**
** Created: Wed Oct 5 14:20:12 2022
**      by: The User Interface Compiler ($Id: qt/main.cpp   3.3.3   edited Nov 24 2003 $)
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#include "quitform.h"

#include <qvariant.h>
#include <qpushbutton.h>
#include <qlabel.h>
#include <qlineedit.h>
#include <qlayout.h>
#include <qtooltip.h>
#include <qwhatsthis.h>
#include "quitform.ui.h"

/*
 *  Constructs a quitDialog as a child of 'parent', with the
 *  name 'name' and widget flags set to 'f'.
 *
 *  The dialog will by default be modeless, unless you set 'modal' to
 *  TRUE to construct a modal dialog.
 */
quitDialog::quitDialog( QWidget* parent, const char* name, bool modal, WFlags fl )
    : QDialog( parent, name, modal, fl )
{
    if ( !name )
	setName( "quitDialog" );

    QWidget* privateLayoutWidget = new QWidget( this, "layout4" );
    privateLayoutWidget->setGeometry( QRect( 10, 10, 360, 100 ) );
    layout4 = new QVBoxLayout( privateLayoutWidget, 11, 6, "layout4"); 

    layout3 = new QHBoxLayout( 0, 0, 6, "layout3"); 

    textLabel1 = new QLabel( privateLayoutWidget, "textLabel1" );
    layout3->addWidget( textLabel1 );
    spacer1 = new QSpacerItem( 191, 21, QSizePolicy::Expanding, QSizePolicy::Minimum );
    layout3->addItem( spacer1 );
    layout4->addLayout( layout3 );

    quitLineEdit = new QLineEdit( privateLayoutWidget, "quitLineEdit" );
    layout4->addWidget( quitLineEdit );

    layout1 = new QHBoxLayout( 0, 0, 6, "layout1"); 

    okButton = new QPushButton( privateLayoutWidget, "okButton" );
    layout1->addWidget( okButton );

    cancelButton = new QPushButton( privateLayoutWidget, "cancelButton" );
    layout1->addWidget( cancelButton );

    clearButton = new QPushButton( privateLayoutWidget, "clearButton" );
    layout1->addWidget( clearButton );

    defaultButton = new QPushButton( privateLayoutWidget, "defaultButton" );
    layout1->addWidget( defaultButton );
    layout4->addLayout( layout1 );
    languageChange();
    resize( QSize(385, 124).expandedTo(minimumSizeHint()) );
    clearWState( WState_Polished );

    // signals and slots connections
    connect( okButton, SIGNAL( clicked() ), this, SLOT( accept() ) );
    connect( cancelButton, SIGNAL( clicked() ), this, SLOT( reject() ) );
    connect( clearButton, SIGNAL( clicked() ), this, SLOT( clearMsg() ) );
    connect( quitLineEdit, SIGNAL( textChanged(const QString&) ), this, SLOT( enableOkButton(const QString&) ) );
}

/*
 *  Destroys the object and frees any allocated resources
 */
quitDialog::~quitDialog()
{
    // no need to delete child widgets, Qt does it all for us
}

/*
 *  Sets the strings of the subwidgets using the current
 *  language.
 */
void quitDialog::languageChange()
{
    setCaption( tr( "Quit Message" ) );
    textLabel1->setText( tr( "Enter Quit Message" ) );
    okButton->setText( tr( "OK" ) );
    cancelButton->setText( tr( "Cancel" ) );
    clearButton->setText( tr( "Clear" ) );
    defaultButton->setText( tr( "Default" ) );
}

