/*
    Mac OS Portions of the bootstrap window class

    Sergei L. Kosakovsky Pond, Spring 2000 - December 2002.
*/

#include "HYParameterTable.h"


//__________________________________________________________________


bool        _HYBootstrapWindow::_ProcessMenuSelection (long msel)
{
    long        menuChoice = msel&0x0000ffff;

    HiliteMenu(0);
    InvalMenuBar();

    switch (msel/0xffff) {
    case 129: { // file menu
        if (menuChoice==4) { // print
            DoSave ();
            return true;
        } else if (menuChoice==8) { // print
            _HYTable* t =  (_HYTable*)GetCellObject (2,0);
            t->_PrintTable((_HYTable*)GetCellObject (1,0));
            return true;
        }

        break;
    }
    }

    if (_HYTWindow::_ProcessMenuSelection(msel)) {
        return true;
    }

    return false;
}




//EOF