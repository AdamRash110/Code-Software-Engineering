package QuizMaker;
import java.io.*;
import java.util.ArrayList;

public class QuizUtils {
    public static String FILE_NAME = "quizzes.txt";
    public static void saveQuiz(Quiz quiz) {
        try {
            FileWriter writer = new FileWriter(FILE_NAME, true);
            writer.write("QUIZ:" + quiz.title + "\n");

            for (int i = 0; i < quiz.questions.size(); i++) {
                writer.write(quiz.questions.get(i) + "::" + quiz.answers.get(i) + "\n");
            }
            writer.write("END\n");
            writer.close();
        } catch (IOException e) {
            System.out.println("Error saving quiz.");
        }
    }
    public static ArrayList<Quiz> loadQuizzes() {
        ArrayList<Quiz> quizzes = new ArrayList<>();
        try {
            BufferedReader reader = new BufferedReader(new FileReader(FILE_NAME));
            String line;
            Quiz quiz = null;
            while ((line = reader.readLine()) != null) {
                if (line.startsWith("QUIZ:")) {
                    String title = line.substring(5);
                    quiz = new Quiz(title);
                } else if (line.equals("END")) {
                    if (quiz != null) {
                        quizzes.add(quiz);
                    }
                } else if (quiz != null) {
                    String[] parts = line.split("::");
                    if (parts.length == 2) {
                        quiz.addQuestion(parts[0], parts[1]);
                    }
                }
            }
            reader.close();
        } catch (IOException e) {
            System.out.println("Error reading quizzes.");
        }
        return quizzes;
    }
}