Результат програми з кортежами:
using System;
using System.Collections.Generic;

class Program
{
    static void Main()
    {
        // Налаштування для коректного відображення кирилиці
        Console.OutputEncoding = System.Text.Encoding.UTF8;
        Console.InputEncoding = System.Text.Encoding.UTF8;

        // Список кортежів (ПІБ, Рік, Оцінки, Сер. бал)
        var applicants = new List<(string FullName, int BirthYear, int[] Grades, double AverageScore)>();
        
        Console.Write("Кількість абітурієнтів: ");
        if (!int.TryParse(Console.ReadLine(), out int n)) return;

        for (int i = 0; i < n; i++)
        {
            Console.WriteLine($"\nВведіть дані абітурієнта №{i + 1}:");
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
            
            Console.Write("Середній бал атестата (через кому): ");
            double avg = double.Parse(Console.ReadLine());
            
            applicants.Add((name, year, grades, avg));
        }

        // 1. Видалення за номером
        Console.Write("\nВведіть номер для видалення (починаючи з 0): ");
        int indexToRemove = int.Parse(Console.ReadLine());
        if (indexToRemove >= 0 && indexToRemove < applicants.Count)
        {
            applicants.RemoveAt(indexToRemove);
            Console.WriteLine("Запис видалено.");
        }

        // 2. Додавання після прізвища
        Console.Write("\nВведіть прізвище, після якого додати новий запис: ");
        string targetName = Console.ReadLine();
        int insertIndex = applicants.FindIndex(a => a.FullName.Contains(targetName));

        if (insertIndex != -1)
        {
            Console.WriteLine("Введіть дані нового абітурієнта:");
            Console.Write("ПІБ: ");
            string name = Console.ReadLine();
            Console.Write("Рік народження: ");
            int year = int.Parse(Console.ReadLine());
            int[] grades = new int[3] { 5, 5, 5 }; // Для прикладу ставимо фіксовані оцінки
            Console.Write("Середній бал: ");
            double avg = double.Parse(Console.ReadLine());
            
            applicants.Insert(insertIndex + 1, (name, year, grades, avg));
        }

        Console.WriteLine("\n--- Список (Кортежі) ---");
        foreach (var a in applicants)
        {
            Console.WriteLine($"{a.FullName} | {a.BirthYear} | Оцінки: {string.Join(", ", a.Grades)} | Бал: {a.AverageScore}");
        }
    }
}
