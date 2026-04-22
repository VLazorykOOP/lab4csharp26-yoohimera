using System;
using System.Collections.Generic;

struct ApplicantStruct
{
    public string FullName;
    public int BirthYear;
    public int[] Grades;
    public double AverageScore;
}

class Program
{
    static void Main()
    {
        Console.OutputEncoding = System.Text.Encoding.UTF8;
        Console.InputEncoding = System.Text.Encoding.UTF8;
        List<ApplicantStruct> applicants = new List<ApplicantStruct>();
        
        Console.Write("Кількість абітурієнтів: ");
        int n = int.Parse(Console.ReadLine());

        for (int i = 0; i < n; i++)
        {
            ApplicantStruct app = new ApplicantStruct();
            Console.Write("ПІБ: ");
            app.FullName = Console.ReadLine();
            Console.Write("Рік народження: ");
            app.BirthYear = int.Parse(Console.ReadLine());
            app.Grades = new int[3];
            for (int j = 0; j < 3; j++)
            {
                Console.Write($"Оцінка {j + 1}: ");
                app.Grades[j] = int.Parse(Console.ReadLine());
            }
            Console.Write("Середній бал: ");
            app.AverageScore = double.Parse(Console.ReadLine());
            applicants.Add(app);
        }

        Console.Write("Індекс для видалення: ");
        int indexToRemove = int.Parse(Console.ReadLine());
        if (indexToRemove >= 0 && indexToRemove < applicants.Count)
        {
            applicants.RemoveAt(indexToRemove);
        }

        Console.Write("Прізвище для пошуку: ");
        string targetName = Console.ReadLine();
        int insertIndex = applicants.FindIndex(a => a.FullName.Contains(targetName));

        if (insertIndex != -1)
        {
            ApplicantStruct newApp = new ApplicantStruct();
            Console.WriteLine("Введіть дані нового абітурієнта:");
            Console.Write("ПІБ: ");
            newApp.FullName = Console.ReadLine();
            Console.Write("Рік народження: ");
            newApp.BirthYear = int.Parse(Console.ReadLine());
            newApp.Grades = new int[3];
            for (int j = 0; j < 3; j++)
            {
                Console.Write($"Оцінка {j + 1}: ");
                newApp.Grades[j] = int.Parse(Console.ReadLine());
            }
            Console.Write("Середній бал: ");
            newApp.AverageScore = double.Parse(Console.ReadLine());

            applicants.Insert(insertIndex + 1, newApp);
        }

        Console.WriteLine("\nРезультат:");
        foreach (var a in applicants)
        {
            Console.WriteLine($"{a.FullName} | {a.BirthYear} | {a.Grades[0]}, {a.Grades[1]}, {a.Grades[2]} | {a.AverageScore}");
        }
    }
}
