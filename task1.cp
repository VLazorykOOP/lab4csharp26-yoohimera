using System;

class DRomb
{
    public double a;
    public double d1;
    public double d2;
    public string color;

    public DRomb(double a, double d1, double d2, string color)
    {
        this.a = a;
        this.d1 = d1;
        this.d2 = d2;
        this.color = color;
    }

    public object this[int index]
    {
        get
        {
            if (index == 0) return d1;
            if (index == 1) return d2;
            if (index == 2) return color;
            throw new Exception("Помилка: Недопустиме значення індексу!");
        }
        set
        {
            if (index == 0) d1 = Convert.ToDouble(value);
            else if (index == 1) d2 = Convert.ToDouble(value);
            else if (index == 2) color = Convert.ToString(value);
            else throw new Exception("Помилка: Недопустиме значення індексу!");
        }
    }

    public static DRomb operator ++(DRomb r)
    {
        r.a += 1;
        r.d1 += 1;
        return r;
    }

    public static DRomb operator --(DRomb r)
    {
        r.a -= 1;
        r.d1 -= 1;
        return r;
    }

    public static bool operator true(DRomb r)
    {
        return r.d1 == r.d2;
    }

    public static bool operator false(DRomb r)
    {
        return r.d1 != r.d2;
    }

    public static DRomb operator +(DRomb r, double scalar)
    {
        return new DRomb(r.a, r.d1 + scalar, r.d2 + scalar, r.color);
    }

    public static DRomb operator +(double scalar, DRomb r)
    {
        return r + scalar;
    }

    public static implicit operator string(DRomb r)
    {
        return $"a={r.a}, d1={r.d1}, d2={r.d2}, color={r.color}";
    }

    public static explicit operator DRomb(string s)
    {
        string[] parts = s.Split(',');
        if (parts.Length == 4)
        {
            return new DRomb(
                double.Parse(parts[0]),
                double.Parse(parts[1]),
                double.Parse(parts[2]),
                parts[3].Trim()
            );
        }
        throw new Exception("Помилка формату.");
    }
}

class Program
{
    static void Main()
    {
        Console.OutputEncoding = System.Text.Encoding.UTF8;

        try
        {
            DRomb romb = new DRomb(5, 6, 8, "Червоний");
            Console.WriteLine((string)romb);

            Console.WriteLine(romb[0]);
            Console.WriteLine(romb[1]);
            Console.WriteLine(romb[2]);

            romb[2] = "Синій";
            Console.WriteLine((string)romb);

            romb++;
            Console.WriteLine((string)romb);

            romb--;
            Console.WriteLine((string)romb);

            DRomb newRomb = romb + 10.5;
            Console.WriteLine((string)newRomb);

            DRomb squareRomb = new DRomb(5, 7.07, 7.07, "Зелений");

            if (squareRomb) Console.WriteLine("Квадрат");
            else Console.WriteLine("Не квадрат");

            if (romb) Console.WriteLine("Квадрат");
            else Console.WriteLine("Не квадрат");

            string strRomb = squareRomb;
            Console.WriteLine(strRomb);

            DRomb parsedRomb = (DRomb)"10,12,12,Жовтий";
            Console.WriteLine((string)parsedRomb);
        }
        catch (Exception ex)
        {
            Console.WriteLine(ex.Message);
        }
    
