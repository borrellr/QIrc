/****************************************************************************
** Form implementation generated from reading ui file 'xircform.ui'
**
** Created: Sat Sep 3 17:20:01 2022
**      by: The User Interface Compiler ($Id: qt/main.cpp   3.3.3   edited Nov 24 2003 $)
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#include "xircform.h"

#include <qvariant.h>
#include <qtextbrowser.h>
#include <qlineedit.h>
#include <qlayout.h>
#include <qtooltip.h>
#include <qwhatsthis.h>
#include <qimage.h>
#include <qpixmap.h>

/*
 *  Constructs a xIrcForm as a child of 'parent', with the
 *  name 'name' and widget flags set to 'f'.
 */
xIrcForm::xIrcForm( QWidget* parent, const char* name, WFlags fl )
    : QWidget( parent, name, fl )
{
    if ( !name )
	setName( "xIrcForm" );
    xIrcFormLayout = new QVBoxLayout( this, 11, 6, "xIrcFormLayout"); 

    Display = new QTextBrowser( this, "Display" );
    Display->setMinimumSize( QSize( 550, 300 ) );
    Display->setVScrollBarMode( QTextBrowser::AlwaysOn );
    Display->setTextFormat( QTextBrowser::LogText );
    xIrcFormLayout->addWidget( Display );

    lineEdit1 = new QLineEdit( this, "lineEdit1" );
    xIrcFormLayout->addWidget( lineEdit1 );
    languageChange();
    resize( QSize(572, 349).expandedTo(minimumSizeHint()) );
    clearWState( WState_Polished );
}

/*
 *  Destroys the object and frees any allocated resources
 */
xIrcForm::~xIrcForm()
{
    // no need to delete child widgets, Qt does it all for us
}

/*
 *  Sets the strings of the subwidgets using the current
 *  language.
 */
void xIrcForm::languageChange()
{
    setCaption( tr( "xIrcDisplay" ) );
}

