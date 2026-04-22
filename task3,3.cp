using System;
using System.Collections.Generic;

// Оголошення запису
record ApplicantRecord(string FullName, int BirthYear, int[] Grades, double AverageScore);

class Program
{
    static void Main()
    {
        Console.OutputEncoding = System.Text.Encoding.UTF8;
        Console.InputEncoding = System.Text.Encoding.UTF8;

        List<ApplicantRecord> applicants = new List<ApplicantRecord>();
        
        Console.Write("Кількість абітурієнтів: ");
        int n = int.Parse(Console.ReadLine());

        for (int i = 0; i < n; i++)
        {
            Console.WriteLine($"\nДані №{i + 1}:");
            Console.Write("ПІБ: ");
            string name = Console.ReadLine();
            Console.Write("Рік народження: ");
            int year = int.Parse(Console.ReadLine());
            int[] grades = new int[3];
            for (int j = 0; j < 3; j++)
            {
                Console.Write($"Оцінка {j + 1}: ");
                grades[j] = int.Parse(Console.ReadLine());
            }
            Console.Write("Середній бал: ");
            double avg = double.Parse(Console.ReadLine());
            
            applicants.Add(new ApplicantRecord(name, year, grades, avg));
        }

        // Видалення
        Console.Write("\nНомер для видалення: ");
        int idx = int.Parse(Console.ReadLine());
        if (idx >= 0 && idx < applicants.Count) applicants.RemoveAt(idx);

        // Пошук та додавання
        Console.Write("\nПрізвище для пошуку: ");
        string search = Console.ReadLine();
        int foundIdx = applicants.FindIndex(a => a.FullName.Contains(search));

        if (foundIdx != -1)
        {
            Console.WriteLine("Додавання нового:");
            // Створення нового об'єкта запису
            applicants.Insert(foundIdx + 1, new ApplicantRecord("Новий Абітурієнт", 2006, new int[] { 4, 4, 4 }, 9.5));
        }

        Console.WriteLine("\n--- Список (Записи) ---");
        applicants.ForEach(a => Console.WriteLine(a));
    }
}
