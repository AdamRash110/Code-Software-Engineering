using System;
class Menu
{
    public static void DisplayMenu()
    {
        while (true)
        {
            Console.WriteLine("\n--- Random Motivation Generator ---");
            Console.WriteLine("1. Get a random motivational quote");
            Console.WriteLine("2. Get a random affirmation");
            Console.WriteLine("3. Get a random daily challenge");
            Console.WriteLine("4. Add a new motivational quote");
            Console.WriteLine("5. Save quotes to file");
            Console.WriteLine("6. Load quotes from file");
            Console.WriteLine("7. Exit");
            Console.Write("Enter your choice: ");
            
            string? choice = Console.ReadLine();
            if (string.IsNullOrEmpty(choice))
            {
                Console.WriteLine("Input cannot be empty. Please try again.");
                continue;
            }

            switch (choice)
            {
                case "1":
                    QuoteManager.DisplayRandomQuote();
                    break;
                case "2":
                    QuoteManager.DisplayAffirmation();
                    break;
                case "3":
                    QuoteManager.DisplayChallenge();
                    break;
                case "4":
                    Console.Write("Enter your new motivational quote: ");
                    string? newQuote = Console.ReadLine();
                    if (!string.IsNullOrEmpty(newQuote))
                    {
                        QuoteManager.AddNewQuote(newQuote);
                    }
                    else
                    {
                        Console.WriteLine("Quote cannot be empty.");
                    }
                    break;
                case "5":
                    FileHandler.SaveQuotesToFile();
                    break;
                case "6":
                    FileHandler.LoadQuotesFromFile();
                    break;
                case "7":
                    Console.WriteLine("Thank you for using the Random Motivation Generator. Goodbye!");
                    return;
                default:
                    Console.WriteLine("Invalid choice. Please try again.");
                    break;
            }
        }
    }
}