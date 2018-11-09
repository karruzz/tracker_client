/*
 * iframe.h
 *
 *  Created on: Nov 8, 2018
 *  Copyright © 2018-2080 Ilja Karasev. All rights reserved.
 *     License: GNU GPL 3
 */

#ifndef IFRAME_H
#define IFRAME_H

#include <QtGlobal>

class IFrame
{
    public:
        quint64 Counter;

        virtual int Size() = 0;
};

#endif // IFRAME_H

