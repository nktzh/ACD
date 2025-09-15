using System;

enum Zhanr
{
    Adventure,
    Sports,
    Simulator,
    Action,
    Strategy,
}

struct Date
{
    public int Day;
    public int Month;
    public int Year;

    public Date(int day, int month, int year)
    {
        Day = day;
        Month = month;
        Year = year;
    }

    public override string ToString()
    {
        return $"{Day:D2}.{Month:D2}.{Year}";
    }
}

struct Game
{
    public string Title;
    public Zhanr GameGenre;
    public string Publisher;
    public Date PurchaseDate;
    public bool IsCompleted;

    public Game(string title, Zhanr genre, string publisher, Date date, bool completed)
    {
        Title = title;
        GameGenre = genre;
        Publisher = publisher;
        PurchaseDate = date;
        IsCompleted = completed;
    }

    public void PrintInformation()
    {
        Console.WriteLine($"  Тайтл: {Title}");
        Console.WriteLine($"  Разработчик: {Publisher}");
        Console.WriteLine($"  Жанр: {GameGenre}");
        Console.WriteLine($"  Пройдена: {(IsCompleted ? "ДА" : "НЕТ")}");
        Console.WriteLine($"  Дата покупки: {PurchaseDate}");
        Console.WriteLine("+-----------------------------------------+");
    }
}

class Program
{
    static void Main()
    {
        Game[] games = new Game[]
        {

            new Game("Cybeprunk 2077", Zhanr.Action, "CD Projekt Red", new Date(15, 6, 2020), true),

            new Game("FOOTBALL", Zhanr.Sports, "EA Sports", new Date(1, 10, 2021), false),

            new Game("BIOSHOK", Zhanr.Action, "2K Games", new Date(20, 5, 2019), false),

            new Game("GTA VI", Zhanr.Action, "RockstAr", new Date(10, 3, 2018), true),

            new Game("FORZA HORIZON 5", Zhanr.Simulator, "Microsoft", new Date(18, 8, 2020), false)

        };
        Console.WriteLine("  * Игры, которые предстоит пройти:\n");
        foreach (var game in games)
        {
            if (!game.IsCompleted)
            {
                game.PrintInformation();
            }
        }
    }
}
