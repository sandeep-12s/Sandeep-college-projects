<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>NexCal - The Precision Engine</title>
    <style>
        /* CSS: Yahan aapki styling hai */
        * { margin: 0; padding: 0; box-sizing: border-box; }
        body {
            background: radial-gradient(circle, #1e293b 0%, #0f172a 100%);
            display: flex;
            justify-content: center;
            align-items: center;
            height: 100vh;
            font-family: 'Segoe UI', Tahoma, Geneva, Verdana, sans-serif;
        }
        .calculator-card {
            background: #1e293b;
            padding: 25px;
            border-radius: 24px;
            box-shadow: 0 25px 50px -12px rgba(0, 0, 0, 0.7);
            width: 340px;
            border: 1px solid #334155;
        }
        .brand {
            color: #38bdf8;
            text-align: center;
            font-size: 1.5rem;
            letter-spacing: 5px;
            margin-bottom: 20px;
            text-shadow: 0 0 10px rgba(56, 189, 248, 0.3);
        }
        .display {
            background: #0f172a;
            color: #f8fafc;
            text-align: right;
            padding: 25px;
            border-radius: 15px;
            margin-bottom: 25px;
            border: 1px solid #334155;
        }
        #previous-op { font-size: 0.9rem; color: #64748b; min-height: 1.2rem; margin-bottom: 5px; }
        #current-val { font-size: 2.2rem; font-weight: bold; overflow: hidden; }
        .buttons {
            display: grid;
            grid-template-columns: repeat(4, 1fr);
            gap: 12px;
        }
        .btn {
            padding: 18px;
            border: none;
            border-radius: 12px;
            background: #334155;
            color: #f8fafc;
            font-size: 1.3rem;
            font-weight: 600;
            cursor: pointer;
            transition: all 0.2s ease;
        }
        .btn:hover { background: #475569; transform: translateY(-2px); }
        .btn:active { transform: translateY(0px); }
        .operator { background: #0ea5e9; color: white; }
        .operator:hover { background: #38bdf8; }
        .equal { background: #22c55e; grid-column: span 2; }
        .equal:hover { background: #4ade80; }
        .clear { background: #ef4444; grid-column: span 2; }
        .clear:hover { background: #f87171; }
    </style>
</head>
<body>

    <div class="calculator-card">
        <h2 class="brand">NEXCAL</h2>
        
        <div class="display">
            <div id="previous-op"></div>
            <div id="current-val">0</div>
        </div>

        <div class="buttons">
            <button class="btn clear" onclick="clearDisplay()">CLEAR</button>
            <button class="btn operator" onclick="setOp('/')">÷</button>
            <button class="btn operator" onclick="setOp('*')">×</button>

            <button class="btn" onclick="appendNum('7')">7</button>
            <button class="btn" onclick="appendNum('8')">8</button>
            <button class="btn" onclick="appendNum('9')">9</button>
            <button class="btn operator" onclick="setOp('-')">−</button>

            <button class="btn" onclick="appendNum('4')">4</button>
            <button class="btn" onclick="appendNum('5')">5</button>
            <button class="btn" onclick="appendNum('6')">6</button>
            <button class="btn operator" onclick="setOp('+')">+</button>

            <button class="btn" onclick="appendNum('1')">1</button>
            <button class="btn" onclick="appendNum('2')">2</button>
            <button class="btn" onclick="appendNum('3')">3</button>
            <button class="btn" onclick="appendNum('.')">.</button>

            <button class="btn" onclick="appendNum('0')">0</button>
            <button class="btn equal" onclick="calculate()">=</button>
        </div>
    </div>

    <script>
        /* JavaScript: Yahan aapka Switch Case logic hai */
        let currentInput = '0';
        let previousInput = '';
        let operator = null;

        const currentValDisplay = document.getElementById('current-val');
        const previousOpDisplay = document.getElementById('previous-op');

        function updateDisplay() {
            currentValDisplay.innerText = currentInput;
            previousOpDisplay.innerText = previousInput + " " + (operator || "");
        }

        function appendNum(num) {
            if (currentInput === '0' && num !== '.') {
                currentInput = num;
            } else {
                if (num === '.' && currentInput.includes('.')) return;
                currentInput += num;
            }
            updateDisplay();
        }

        function setOp(op) {
            if (operator !== null) calculate();
            operator = op;
            previousInput = currentInput;
            currentInput = '0';
            updateDisplay();
        }

        function calculate() {
            let result;
            const prev = parseFloat(previousInput);
            const current = parseFloat(currentInput);

            if (isNaN(prev) || isNaN(current)) return;

            // Integrated your C-code logic here
            switch(operator) {
                case '+': result = prev + current; break;
                case '-': result = prev - current; break;
                case '*': result = prev * current; break;
                case '/': 
                    if(current === 0) {
                        alert("ERROR: Number is not divisible by zero");
                        clearDisplay();
                        return;
                    }
                    result = prev / current; 
                    break;
                default: return;
            }
            
            // To keep results clean like your %.3f
            currentInput = Math.round(result * 1000) / 1000;
            currentInput = currentInput.toString();
            operator = null;
            previousInput = '';
            updateDisplay();
        }

        function clearDisplay() {
            currentInput = '0';
            previousInput = '';
            operator = null;
            updateDisplay();
        }
    </script>
</body>
</html>
