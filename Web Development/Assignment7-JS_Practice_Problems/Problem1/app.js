const questionContainer = document.getElementById('question-container');
const answerButtonsContainer = document.getElementById('answer-buttons');
const submitButton = document.getElementById('submit-button');
const popup = document.getElementById('popup');
const popupText = document.getElementById('popup-text');
const nextButton = document.getElementById('next-button');
const leaderboardContainer = document.getElementById('leaderboard-container');
const leaderboard = document.getElementById('leaderboard');

let currentQuestionIndex = 0;
let score = 0;
let correctAnswers = 0;
let incorrectAnswers = 0;

// Function to start the quiz
function startQuiz() {
    // Hide start button and show quiz container
    document.getElementById('start-button').style.display = 'none';
    document.getElementById('quiz-container').style.display = 'block';

    // Display first question
    showQuestion();
}

// Function to display a question
function showQuestion() {
    // Clear previous question and answer buttons
    questionContainer.innerHTML = '';
    answerButtonsContainer.innerHTML = '';

    // Get current question
    const question = questions[currentQuestionIndex];

    // Display question
    questionContainer.innerText = question.question;

    // Create answer buttons
    question.answers.forEach(answer => {
        const button = document.createElement('button');
        button.innerText = answer.text;
        button.classList.add('button');
        if (answer.correct) {
            button.dataset.correct = answer.correct;
        }
        button.addEventListener('click', selectAnswer);
        answerButtonsContainer.appendChild(button);
    });
}

// Function to select an answer
function selectAnswer(e) {
    const selectedButton = e.target;
    const correct = selectedButton.dataset.correct;

    // Update score based on the selected answer
    if (correct) {
        score++;
        correctAnswers++;
        showPopup(true);
    } else {
        incorrectAnswers++;
        showPopup(false);
    }

    // Disable all answer buttons after selection
    Array.from(answerButtonsContainer.children).forEach(button => {
        button.disabled = true;
    });

    // Enable submit button
    submitButton.disabled = false;
}

// Function to show a popup indicating the result of the selected answer
function showPopup(correct) {
    popup.style.display = 'block';

    if (correct) {
        popupText.innerText = 'Correct!';
        popupText.style.color = 'green';
    } else {
        popupText.innerText = 'Wrong!';
        popupText.style.color = 'red';
    }
}

// Function to hide the popup and proceed to the next question
function nextQuestion() {
    popup.style.display = 'none';
    currentQuestionIndex++;

    // If there are more questions, show the next question
    if (currentQuestionIndex < questions.length) {
        showQuestion();
    } else {
        // If all questions are answered, show the leaderboard
        showLeaderboard();
    }

    // Enable all answer buttons
    Array.from(answerButtonsContainer.children).forEach(button => {
        button.disabled = false;
    });

    // Disable submit button
    submitButton.disabled = true;
}

// Function to show the leaderboard
function showLeaderboard() {
    leaderboardContainer.style.display = 'block';

    // Display user's score and overall result
    leaderboard.innerHTML = `
        <p>Correct Answers: ${correctAnswers}</p>
        <p>Incorrect Answers: ${incorrectAnswers}</p>
        <p>Score: ${score}</p>
    `;
}

// Add event listener to submit button
submitButton.addEventListener('click', nextQuestion);

// Add event listener to next button in popup
nextButton.addEventListener('click', nextQuestion);

// Start the quiz
startQuiz();
