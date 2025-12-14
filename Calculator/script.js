let display = document.getElementById('result');
let currentInput = '';
let operator = '';
let previousInput = '';
let shouldResetDisplay = false;

function appendToDisplay(value) {
    if (shouldResetDisplay) {
        display.value = '';
        shouldResetDisplay = false;
    }
    
    // Handle decimal point
    if (value === '.') {
        if (display.value.includes('.')) {
            return; // Don't add multiple decimal points
        }
        if (display.value === '' || display.value === '0') {
            display.value = '0.';
            return;
        }
    }
    
    // Handle operators
    if (['+', '-', '*', '/'].includes(value)) {
        if (currentInput !== '' && operator !== '' && !shouldResetDisplay) {
            calculate();
        }
        operator = value === '×' ? '*' : value;
        previousInput = display.value;
        shouldResetDisplay = true;
        return;
    }
    
    // Handle numbers
    if (display.value === '0' && value !== '.') {
        display.value = value;
    } else {
        display.value += value;
    }
    
    currentInput = display.value;
}

function clearDisplay() {
    display.value = '';
    currentInput = '';
    operator = '';
    previousInput = '';
    shouldResetDisplay = false;
}

function deleteLast() {
    if (display.value.length > 0) {
        display.value = display.value.slice(0, -1);
        currentInput = display.value;
    }
}

function calculate() {
    if (previousInput === '' || currentInput === '' || operator === '') {
        return;
    }
    
    let result;
    const prev = parseFloat(previousInput);
    const current = parseFloat(currentInput);
    
    if (isNaN(prev) || isNaN(current)) {
        return;
    }
    
    switch (operator) {
        case '+':
            result = prev + current;
            break;
        case '-':
            result = prev - current;
            break;
        case '*':
            result = prev * current;
            break;
        case '/':
            if (current === 0) {
                display.value = 'Error';
                resetCalculator();
                return;
            }
            result = prev / current;
            break;
        default:
            return;
    }
    
    // Round to avoid floating point precision issues
    result = Math.round((result + Number.EPSILON) * 100000000) / 100000000;
    
    display.value = result.toString();
    currentInput = result.toString();
    operator = '';
    previousInput = '';
    shouldResetDisplay = true;
}

function resetCalculator() {
    setTimeout(() => {
        clearDisplay();
    }, 1500);
}

// Keyboard support
document.addEventListener('keydown', function(event) {
    const key = event.key;
    
    // Numbers and decimal point
    if ((key >= '0' && key <= '9') || key === '.') {
        appendToDisplay(key);
    }
    
    // Operators
    else if (key === '+' || key === '-') {
        appendToDisplay(key);
    }
    else if (key === '*') {
        appendToDisplay('×');
    }
    else if (key === '/') {
        event.preventDefault(); // Prevent browser search
        appendToDisplay('/');
    }
    
    // Enter or equals
    else if (key === 'Enter' || key === '=') {
        event.preventDefault();
        calculate();
    }
    
    // Escape or 'c' for clear
    else if (key === 'Escape' || key.toLowerCase() === 'c') {
        clearDisplay();
    }
    
    // Backspace for delete
    else if (key === 'Backspace') {
        event.preventDefault();
        deleteLast();
    }
});

// Initialize display
display.value = '';
