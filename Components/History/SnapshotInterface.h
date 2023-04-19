//
// Created by Raina Wan on 3/29/23.
//

#ifndef MENU_SNAPSHOTINTERFACE_H
#define MENU_SNAPSHOTINTERFACE_H
#include "Snapshot.h"

class SnapshotInterface {
public:
    virtual Snapshot* getSnapshot() = 0;
    virtual void applySnapshot(Snapshot* snapshot) = 0;
};


#endif //MENU_SNAPSHOTINTERFACE_H
