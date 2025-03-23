using System;
using System.Collections.Generic;

class QuoteManager
{
    private static List<string> quotes = new List<string>
    {
        "Believe in yourself!",
        "Keep going! You are doing amazing!",
        "You are capable of great things!",
    };

    private static List<string> affirmations = new List<string>
    {
        "I am strong and encouraging!",
        "I choose to be happy today!",
        "I am in charge of my own life and destiny!",
        "I have the power to create positive things for others and myself!",
    };

    private static List<string> challenges = new List<string>
    {
        "Take a 10-30 minute walk today to relax!",
        "Write down three things you find positive about yourself!",
        "Make sure to eat when you need it and drink as well!",
        "Try to compliment someone to make their day today!",
    };

    public static void DisplayRandomQuote()
    {
        Random random = new Random();
        int index = random.Next(quotes.Count);
        Console.WriteLine($"\nYour motivational quote: \"{quotes[index]}\"");
    }

    public static void DisplayAffirmation()
    {
        Random random = new Random();
        int index = random.Next(affirmations.Count);
        Console.WriteLine($"\nYour affirmation: \"{affirmations[index]}\"");
    }

    public static void DisplayChallenge()
    {
        Random random = new Random();
        int index = random.Next(challenges.Count);
        Console.WriteLine($"\nYour daily challenge: \"{challenges[index]}\"");
    }

    public static void AddNewQuote(string newQuote)
    {
        quotes.Add(newQuote);
        Console.WriteLine("New quote added successfully for you!");
    }

    public static List<string> GetAllQuotes()
    {
        return quotes;
    }
}