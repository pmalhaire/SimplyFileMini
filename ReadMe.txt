This is a simple file browser of a dirrectory through HTML5 QT5 ( nice double 5 )

the file listing is made in the controleur
and reexposed through javascript to make is simplier to set the styles dir and files are separated

CppTojs.listFiles(entry);
CppTojs.listDirs(entry);

we have a Widget simplywidget

creating a view
     set up the basic size scrollbar etc
     set up the slot used as a bridge to expose CppTojs javascript functions

creating webview
     additionnal setting could be added here
