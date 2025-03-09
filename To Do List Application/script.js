function addTask() {
    let taskInput = document.getElementById("taskInput");
    let taskList = document.getElementById("taskList");

    if (taskInput.value.trim() !== "") {
        let li = document.createElement("li");
        li.innerHTML = `${taskInput.value} 
            <button onclick="completeTask(this)">✔</button>
            <button onclick="deleteTask(this)">❌</button>`;
        taskList.appendChild(li);
        taskInput.value = "";
    }
}
function completeTask(button) {
    button.parentElement.style.textDecoration = "line-through";
}
function deleteTask(button) {
    button.parentElement.remove();
}
function saveNote() {
    let noteInput = document.getElementById("noteInput");
    let noteList = document.getElementById("noteList");

    if (noteInput.value.trim() !== "") {
        let li = document.createElement("li");
        li.innerHTML = `${noteInput.value} <button onclick="deleteNote(this)">❌</button>`;
        noteList.appendChild(li);
        noteInput.value = "";
    }
}
function deleteNote(button) {
    button.parentElement.remove();
}
let timeLeft = 1500;
let timerInterval;
function startTimer() {
    if (!timerInterval) {
        timerInterval = setInterval(() => {
            if (timeLeft > 0) {
                timeLeft--;
                let minutes = Math.floor(timeLeft / 60);
                let seconds = timeLeft % 60;
                document.getElementById("timer").innerText = 
                    `${minutes}:${seconds < 10 ? '0' : ''}${seconds}`;
            } else {
                clearInterval(timerInterval);
                alert("Time's up!");
            }
        }, 1000);
    }
}
function resetTimer() {
    clearInterval(timerInterval);
    timerInterval = null;
    timeLeft = 1500;
    document.getElementById("timer").innerText = "25:00";
}