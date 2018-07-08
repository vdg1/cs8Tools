#include "vpnconnectivity.h"
#include <windows.h>
#include <stdio.h>
#include "ras.h"
#include "raserror.h"
#include <QDebug>

//#include <QxtBasicFileLoggerEngine>
//#include <QxtLogger>
#pragma comment(lib, "rasapi32.lib")

vpnConnectivity::vpnConnectivity(QObject *parent) :
    QObject(parent)
{
}



bool vpnConnectivity::online()
{

    DWORD dwCb = 0;
    DWORD dwRet = ERROR_SUCCESS;
    DWORD dwConnections = 0;
    LPRASCONN lpRasConn = NULL;

    // Call RasEnumConnections with lpRasConn = NULL. dwCb is returned with the required buffer size and
    // a return code of ERROR_BUFFER_TOO_SMALL
    dwRet = RasEnumConnections(lpRasConn, &dwCb, &dwConnections);

    if (dwRet == ERROR_BUFFER_TOO_SMALL)
    {
        // Allocate the memory needed for the array of RAS structure(s).
        lpRasConn = (LPRASCONN) HeapAlloc(GetProcessHeap(), HEAP_ZERO_MEMORY, dwCb);
        if (lpRasConn == NULL)
        {
            qDebug() << "HeapAlloc failed!";
            return 0;
        }
        // The first RASCONN structure in the array must contain the RASCONN structure size
        lpRasConn[0].dwSize = sizeof(RASCONN);

        // Call RasEnumConnections to enumerate active connections
        dwRet = RasEnumConnections(lpRasConn, &dwCb, &dwConnections);

        // If successful, print the names of the active connections.
        if (ERROR_SUCCESS == dwRet)
        {

            qDebug() << "The following RAS connections are currently active:";
            for (DWORD i = 0; i < dwConnections; i++)
            {
                qDebug() <<  QString::fromWCharArray (lpRasConn[i].szEntryName);
            }

        }
        //Deallocate memory for the connection buffer
        HeapFree(GetProcessHeap(), 0, lpRasConn);
        lpRasConn = NULL;
        return true;
    }

    // There was either a problem with RAS or there are no connections to enumerate
    if (dwConnections >= 1)
    {
        qDebug() << "The operation failed to acquire the buffer size.";
    }
    else
    {
        //qxtLog->info()  << "There are no active RAS connections.";
    }

    return false;
}

