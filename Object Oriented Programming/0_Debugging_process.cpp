/*
    Direct Debugging - Use the binary on certain server can be done directly either via vscode.
        -> setup launch.json file
        -> Make sure you have latest gdb binary (older one gives memory fault in modern c++ functions)
        -> Refer to correct path
        -> Put correct args
        -> if gdb is not being referred and you know it's there, refer the binary path in 'miDebuggerPath' property in launch.json

        If we do not have vscode, and we need terminal, direct gdb also works

    Remote Debugging - The binary is running on some remote host, but the debugging is gonna happen on localhost
        -> For this we need gdbserver (Google on how to set it up on both sides)
        -> On remote host do - gdbserver localhost:available_port binary_name args. Once you press enter, you should be seeing something like ("Listening to ....")
        -> On localhost, if you are using vscode, in launch.json a property has to be added of miRemoteDebuggerSever or something like this, here you specify the remote server name and port
        -> Please note we need same binary locally and on remote server
        -> Now just provide binary path and args and start debugging
*/