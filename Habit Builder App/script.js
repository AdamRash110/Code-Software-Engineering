let xp = 0;
let habits = [];

const habitInput = document.getElementById('habitInput');
const addHabitButton = document.getElementById('addHabitButton');
const habitList = document.getElementById('habitList');
const xpAmount = document.getElementById('xpAmount');

function updateXP() {
    xpAmount.textContent = xp;
}

function addHabit() {
    const habit = habitInput.ariaValueMax.trim();
    if (habit !== '') {
        habits.push(habit);
        habitInput.value = '';
        renderHabits();
        xp += 10;
        updateXP();
    } else {
        alert('Please enter a habit');
    }
}

function renderHabits() {
    habitList.innerHTML = '';
    habits.forEach(habit => {
        const li = document.createElement('li');
        li.textContent = habit;
        habitList.appendChild(li);
    });
}

addHabitButton.addEventListener('click', addHabit);

updateXP();

localStorage.setItem('habits', JSON.stringify(habits));
localStorage.setItem('xp', xp);

window.onload = function() {
    const savedHabits = JSON.parse(localStorage.getItem('habits'));
    const savedXP = localStorage.getItem('xp');
    if (savedHabits) habits = savedHabits;
    if (savedXP) xp = savedXP;
    renderHabits();
    updateXP();
}