# Folder_Locker
Changing Attribute of file using C++ 

Go through Terms file in repository to understand why we used it and what does it signify.

Simple C++ code was designed for the same purpose of what Command prompt would do(hide the folder by changing its attribute):
Secure method to hide your Important stuff as user will not be able to find those hidden file/folder,
even by opening File explorer> View> Checking "Hidden Items" box,the file will still not be visible to the user.

How do we do that?
1:Hide it via Command prompt(Drawback-It's not gonna be password protected)
2:C++ (password gonna keep it more protected than above method)

C++(Method):
Functions used for Folder_Locker:1.Lock() 2.Unlock() 3.getpassword()
1.Lock():First of all the source path of folder/file is required which we want ti hide/lock and to that we add temporary desktop.ini file with unique Class ID(CLSID).After 
doing so we change the attribute to hidden(+h) and prioritize the file in system(+s) and therfore execute the attribute operation.
Ultimately the file is gonna be protected by OS from the general user and will be stored in sysytems registry with unique Identification ID we gave s CLSID.
Therefore,the file/folder is locked

2.Unlock():Undo the attribute change i.e, unhide(-h) and remove it from system file(-s) and therefore unlocking file/folder.

3.Getpassword():Take input from user and return the pass. string after executing enter(Ascii code 13).Change your password in the code and execute the program again to set new password of your locker.

