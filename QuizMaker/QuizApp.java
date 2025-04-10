package QuizMaker;
import java.util.ArrayList;
import java.util.Scanner;

public class QuizApp {
    public static void main(String[] args) {
        try (Scanner scanner = new Scanner(System.in)) {
            boolean running = true;
            
            while (running) {
                System.out.println("\n--- Quiz Maker ---");
                System.out.println("1. Create a Quiz");
                System.out.println("2. Take a Quiz");
                System.out.println("3. Exit");
                System.out.print("Choose: ");
                String input = scanner.nextLine();
                
                switch (input) {
                    case "1" -> createQuiz(scanner);
                    case "2" -> takeQuiz(scanner);
                    case "3" -> running = false;
                    default -> System.out.println("Invalid choice.");
                }
            }
        }
        System.out.println("Bye!");
    }

    public static void createQuiz(Scanner scanner) {
        System.out.print("Quiz title: ");
        String title = scanner.nextLine();
        Quiz quiz = new Quiz(title);

        while (true) {
            System.out.print("Enter question (type 'done' to finish): ");
            String question = scanner.nextLine();
            if (question.equalsIgnoreCase("done")) {
                break;
            }

            System.out.print("Enter answer: ");
            String answer = scanner.nextLine();
            quiz.addQuestion(question, answer);
        }

        QuizUtils.saveQuiz(quiz);
        System.out.println("Quiz saved!");
    }

    public static void takeQuiz(Scanner scanner) {
        ArrayList<Quiz> quizzes = QuizUtils.loadQuizzes();

        if (quizzes.isEmpty()) {
            System.out.println("No quizzes available.");
            return;
        }

        for (int i = 0; i < quizzes.size(); i++) {
            System.out.println((i + 1) + ". " + quizzes.get(i).title);
        }

        System.out.print("Choose quiz number: ");
        int choice = Integer.parseInt(scanner.nextLine()) - 1;

        if (choice < 0 || choice >= quizzes.size()) {
            System.out.println("Invalid choice.");
            return;
        }

        Quiz quiz = quizzes.get(choice);
        int score = 0;

        for (int i = 0; i < quiz.questions.size(); i++) {
            System.out.println("Q: " + quiz.questions.get(i));
            System.out.print("Answer: ");
            String userAnswer = scanner.nextLine();

            if (userAnswer.equalsIgnoreCase(quiz.answers.get(i))) {
                System.out.println("Correct!");
                score++;
            } else {
                System.out.println("Wrong. Correct answer: " + quiz.answers.get(i));
            }
        }

        System.out.println("Score: " + score + "/" + quiz.questions.size());
    }
}