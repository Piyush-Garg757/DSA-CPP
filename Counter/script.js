// Counter application functionality
let counter = 0;

// Get DOM elements
const counterValue = document.getElementById('counter-value');
const increaseBtn = document.getElementById('increase-btn');
const decreaseBtn = document.getElementById('decrease-btn');
const resetBtn = document.getElementById('reset-btn');

// Function to update the counter display
function updateCounter() {
    counterValue.textContent = counter;
    
    // Add animation class
    counterValue.classList.add('counter-animate');
    
    // Remove animation class after animation completes
    setTimeout(() => {
        counterValue.classList.remove('counter-animate');
    }, 300);
    
    // Update counter color based on value
    if (counter > 0) {
        counterValue.style.color = '#4CAF50';
    } else if (counter < 0) {
        counterValue.style.color = '#f44336';
    } else {
        counterValue.style.color = '#333';
    }
}

// Event listeners for buttons
increaseBtn.addEventListener('click', () => {
    counter++;
    updateCounter();
});

decreaseBtn.addEventListener('click', () => {
    counter--;
    updateCounter();
});

resetBtn.addEventListener('click', () => {
    counter = 0;
    updateCounter();
});

// Keyboard support
document.addEventListener('keydown', (event) => {
    switch(event.key) {
        case '+':
        case '=':
            event.preventDefault();
            counter++;
            updateCounter();
            break;
        case '-':
            event.preventDefault();
            counter--;
            updateCounter();
            break;
        case 'r':
        case 'R':
            event.preventDefault();
            counter = 0;
            updateCounter();
            break;
        case 'ArrowUp':
            event.preventDefault();
            counter++;
            updateCounter();
            break;
        case 'ArrowDown':
            event.preventDefault();
            counter--;
            updateCounter();
            break;
    }
});

// Button click effects
function addClickEffect(button) {
    button.addEventListener('mousedown', () => {
        button.style.transform = 'translateY(2px)';
    });
    
    button.addEventListener('mouseup', () => {
        button.style.transform = '';
    });
    
    button.addEventListener('mouseleave', () => {
        button.style.transform = '';
    });
}

// Apply click effects to all buttons
addClickEffect(increaseBtn);
addClickEffect(decreaseBtn);
addClickEffect(resetBtn);

// Initialize the counter display
updateCounter();

// Add some fun features
let clickCount = 0;
const originalTitle = document.title;

// Track total clicks for fun
document.addEventListener('click', () => {
    clickCount++;
    if (clickCount % 10 === 0) {
        document.title = `🎉 ${clickCount} clicks! - ${originalTitle}`;
        setTimeout(() => {
            document.title = originalTitle;
        }, 2000);
    }
});

// Easter egg: Konami code for special effect
let konamiCode = [];
const konamiSequence = ['ArrowUp', 'ArrowUp', 'ArrowDown', 'ArrowDown', 'ArrowLeft', 'ArrowRight', 'ArrowLeft', 'ArrowRight'];

document.addEventListener('keydown', (event) => {
    konamiCode.push(event.key);
    
    if (konamiCode.length > konamiSequence.length) {
        konamiCode.shift();
    }
    
    if (JSON.stringify(konamiCode) === JSON.stringify(konamiSequence)) {
        // Easter egg activated!
        document.body.style.animation = 'rainbow 2s infinite';
        setTimeout(() => {
            document.body.style.animation = '';
        }, 5000);
        konamiCode = [];
    }
});

// Add rainbow animation for easter egg
const style = document.createElement('style');
style.textContent = `
    @keyframes rainbow {
        0% { filter: hue-rotate(0deg); }
        100% { filter: hue-rotate(360deg); }
    }
`;
document.head.appendChild(style);
