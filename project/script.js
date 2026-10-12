function showPage(pageName) {

    // Hide all pages
    const pages = document.querySelectorAll(".page");

    pages.forEach(page => {
        page.classList.remove("active-page");
    });


    // Show selected page
    const selectedPage = document.getElementById(pageName);

    if (selectedPage) {
        selectedPage.classList.add("active-page");
    }


    // Remove active class from menu
    const menus = document.querySelectorAll(".menu");

    menus.forEach(menu => {
        menu.classList.remove("active");
    });


    // Find correct menu
    menus.forEach(menu => {

        if (menu.getAttribute("onclick") === `showPage('${pageName}')`) {
            menu.classList.add("active");
        }

    });

}


/* PROCESS CREATION */

function simulateCreation() {

    const parentPID =
        Math.floor(Math.random() * 9000) + 1000;

    const childPID =
        Math.floor(Math.random() * 9000) + 1000;


    document.getElementById("parentPID").innerText =
        parentPID;

    document.getElementById("childPID").innerText =
        childPID;


    document.getElementById("creationResult").innerHTML =
        "✓ fork() executed successfully. Child process created.";

}


/* PROCESS EXECUTION */

function simulateExecution() {

    document.getElementById("executionResult").innerHTML =
        "✓ exec() executed successfully. Child process is running.";

}


/* PROCESS WAITING */

function simulateWaiting() {

    document.getElementById("waitingResult").innerHTML =
        "✓ Parent process is waiting for child completion.";

}


/* PROCESS TERMINATION */

function simulateTermination() {

    document.getElementById("terminationResult").innerHTML =
        "✓ Process terminated successfully. Exit Status: 0";

}