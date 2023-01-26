function sidebarEntryClicked(element) {
    // Set all inactive
    var allSidebarEntries = Array.from(document.getElementById("sidebar").getElementsByClassName("sidebar-entry"));
    for (var i in allSidebarEntries) {
        allSidebarEntries[i].className = "sidebar-entry";
    }

    // Set clicked one active
    element.className = `${element.className} sidebar-active`;

    // Change main pane
    var mainEntries = document.getElementById("main").getElementsByClassName("main-entry");
    for (var i in mainEntries) {
        mainEntries[i].className = "main-entry";
    }

    var activeEntry = null;
    switch (element.innerHTML) {
        case "Solid":
            activeEntry = document.getElementById("mainSolid");
            break;

        case "Fade":

            break;

        case "Gradient":

            break;
    }

    if (activeEntry != null) {
        activeEntry.className = `${activeEntry.className} main-active`;
    }
}

function solidColourClicked(element) {
    // Get colour class
    var colour = "";
    var classes = element.className.split(' ');
    for (var idx in classes) {
        var cssClass = classes[idx];
        if (cssClass == "col" || cssClass == "rounded-colour") {
            continue;
        }

        colour = cssClass;
        break;
    }

    // Set all inactive
    var allSolidColours = Array.from(document.getElementById("main").getElementsByClassName("rounded-colour"));
    for (var i in allSolidColours) {
        allSolidColours[i].innerHTML = "";
    }

    // Set clicked one active
    var newNode = document.createElement("div");
    newNode.innerHTML = `<svg xmlns="http://www.w3.org/2000/svg" viewBox="0 0 512 512"><!--! Font Awesome Free 6.2.1 by @fontawesome - https://fontawesome.com License - https://fontawesome.com/license/free (Icons: CC BY 4.0, Fonts: SIL OFL 1.1, Code: MIT License) Copyright 2022 Fonticons, Inc. --><path fill="currentColor" stroke="currentColor" d="M470.6 105.4c12.5 12.5 12.5 32.8 0 45.3l-256 256c-12.5 12.5-32.8 12.5-45.3 0l-128-128c-12.5-12.5-12.5-32.8 0-45.3s32.8-12.5 45.3 0L192 338.7 425.4 105.4c12.5-12.5 32.8-12.5 45.3 0z"/></svg>`;
    element.appendChild(newNode);

    // 'Extract colour'
    var r, g, b;
    switch (colour) {
        case "red":
            r = 255; g = 0; b = 0;
            break;

        case "orange":
            r = 255; g = 127; b = 0;
            break;

        case "yellow":
            r = 255; g = 255; b = 0;
            break;

        case "yellow-green":
            r = 127; g = 255; b = 0;
            break;

        case "green":
            r = 0; g = 255; b = 0;
            break;

        case "light-blue":
            r = 0; g = 255; b = 255;
            break;

        case "blue":
            r = 0; g = 0; b = 255;
            break;

        case "purple":
            r = 128; g = 0; b = 255;
            break;

        case "pink":
            r = 255; g = 0; b = 255;
            break;

        case "white":
            r = 255; g = 255; b = 255;
            break;

        case "black":
            r = 0; g = 0; b = 0;
            break;

        case "custom":
            r = 255; g = 255; b = 255;
            break;
    }

    // Send POST request to web server to change colour
    var http = new XMLHttpRequest();
    http.open('POST', "/solid", true);
    http.setRequestHeader("Content-Type", "application/x-www-form-urlencoded");
    http.send(`r=${r}&g=${g}&b=${b}`);
}