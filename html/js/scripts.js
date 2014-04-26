window.onload = function () {
    document.getElementById("list_id").onclick = function () {
        //set entry dir
        var entry = "/";
        var listFiles,listDirs = [];
        var obj = "<ul class=\"fileTree\">";

        //disable button to avoid mutliple calls
        document.getElementById("list_id").disabled = true;


        listFiles = CppToJs.listFiles(entry);
        listDirs = CppToJs.listDirs(entry);

        if (listDirs) {
            for (var i = 0; i < listDirs.length; i++) {
                obj = obj.concat("<li class=\"directory\">");
                obj = obj.concat(listDirs[i]);
                obj = obj.concat("</li>");
            }
        }
        if (listFiles) {
            for (var j = 0; j < listFiles.length; j++) {
                obj = obj.concat("<li class=\"file\">");
                obj = obj.concat(listFiles[j]);
                obj = obj.concat("</li>");
            }
        }
        obj = obj.concat("</ul>");
        document.getElementById("container_id").innerHTML=obj;

        delete listDirs;
        delete listFiles;
    };
    document.getElementById("exit_id").onclick = function () {
        CppToJs.quit();
    };
}

