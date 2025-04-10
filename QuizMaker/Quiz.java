package QuizMaker;
import java.util.ArrayList;

public class Quiz {
    public String title;
    public ArrayList<String> questions;
    public ArrayList<String> answers;
    public Quiz(String title) {
        this.title = title;
        this.questions = new ArrayList<>();
        this.answers = new ArrayList<>();
    }

    public void addQuestion(String question, String answer) {
        questions.add(question);
        answers.add(answer);
    }
}