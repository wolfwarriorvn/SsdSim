// RomCode.cpp : Defines the exported functions for the DLL application.
//

#include <memory>

#include "InterfaceQueues.h"

extern "C"
{
    void __declspec(dllexport) __stdcall Execute(std::shared_ptr<InterfaceQueues> InterfaceQueues)
    {
        if (!InterfaceQueues->CustomProtocolCommandQueue.empty())
        {
            CustomProtocolCommand *command = InterfaceQueues->CustomProtocolCommandQueue.front();
            InterfaceQueues->CustomProtocolCommandQueue.pop();
            switch (command->Command)
            {
                case CommandCode::DownloadAndExecute:
                {
                    // Do download and execute
                } break;
            }
        }
    }
};
