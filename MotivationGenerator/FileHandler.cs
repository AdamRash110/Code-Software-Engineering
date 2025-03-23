using System;
using System.IO;

class FileHandler
{
    private static string filePath = "quotes.txt";
    public static void SaveQuotesToFile()
    {
        File.WriteAllLines(filePath, QuoteManager.GetAllQuotes());
        Console.WriteLine("Quotes saved to file!");
    }

    public static void LoadQuotesFromFile()
    {
        if (File.Exists(filePath))
        {
            string[] savedQuotes = File.ReadAllLines(filePath);
            foreach (string quote in savedQuotes)
            {
                QuoteManager.AddNewQuote(quote);
            }
            Console.WriteLine("Quotes loaded from file!");
        }
        else
        {
            Console.WriteLine("No saved quotes found at all.");
        }
    }
}