using System;

class VectorULong
{
    protected ulong[] IntArray;
    protected uint size;
    protected int codeError;
    protected static uint num_vec;

    public VectorULong()
    {
        size = 1;
        IntArray = new ulong[size];
        IntArray[0] = 0;
        num_vec++;
    }

    public VectorULong(uint size)
    {
        this.size = size;
        IntArray = new ulong[size];
        for (uint i = 0; i < size; i++) IntArray[i] = 0;
        num_vec++;
    }

    public VectorULong(uint size, ulong initValue)
    {
        this.size = size;
        IntArray = new ulong[size];
        for (uint i = 0; i < size; i++) IntArray[i] = initValue;
        num_vec++;
    }

    ~VectorULong()
    {
        Console.WriteLine("Destructor");
    }

    public void Input()
    {
        for (uint i = 0; i < size; i++)
        {
            IntArray[i] = ulong.Parse(Console.ReadLine());
        }
    }

    public void Output()
    {
        for (uint i = 0; i < size; i++)
        {
            Console.Write(IntArray[i] + " ");
        }
        Console.WriteLine();
    }

    public void Assign(ulong value)
    {
        for (uint i = 0; i < size; i++) IntArray[i] = value;
    }

    public static uint GetNumVec()
    {
        return num_vec;
    }

    public uint Size => size;

    public int CodeError
    {
        get => codeError;
        set => codeError = value;
    }

    public ulong this[uint index]
    {
        get
        {
            if (index >= size)
            {
                codeError = -1;
                return 0;
            }
            return IntArray[index];
        }
        set
        {
            if (index >= size)
            {
                codeError = -1;
            }
            else
            {
                IntArray[index] = value;
            }
        }
    }

    public static VectorULong operator ++(VectorULong v)
    {
        for (uint i = 0; i < v.size; i++) v.IntArray[i]++;
        return v;
    }

    public static VectorULong operator --(VectorULong v)
    {
        for (uint i = 0; i < v.size; i++) v.IntArray[i]--;
        return v;
    }

    public static bool operator true(VectorULong v)
    {
        if (v.size == 0) return false;
        foreach (ulong val in v.IntArray)
        {
            if (val != 0) return true;
        }
        return false;
    }

    public static bool operator false(VectorULong v)
    {
        if (v.size == 0) return true;
        foreach (ulong val in v.IntArray)
        {
            if (val != 0) return false;
        }
        return true;
    }

    public static bool operator !(VectorULong v)
    {
        return v.size != 0;
    }

    public static VectorULong operator ~(VectorULong v)
    {
        VectorULong res = new VectorULong(v.size);
        for (uint i = 0; i < v.size; i++) res.IntArray[i] = ~v.IntArray[i];
        return res;
    }

    private static VectorULong BinOp(VectorULong v1, VectorULong v2, Func<ulong, ulong, ulong> op)
    {
        uint maxSize = Math.Max(v1.size, v2.size);
        VectorULong res = new VectorULong(maxSize);
        for (uint i = 0; i < maxSize; i++)
        {
            ulong val1 = i < v1.size ? v1.IntArray[i] : 0;
            ulong val2 = i < v2.size ? v2.IntArray[i] : 0;
            res.IntArray[i] = op(val1, val2);
        }
        return res;
    }

    private static VectorULong BinOpS(VectorULong v, ulong s, Func<ulong, ulong, ulong> op)
    {
        VectorULong res = new VectorULong(v.size);
        for (uint i = 0; i < v.size; i++) res.IntArray[i] = op(v.IntArray[i], s);
        return res;
    }

    public static VectorULong operator +(VectorULong v1, VectorULong v2) => BinOp(v1, v2, (a, b) => a + b);
    public static VectorULong operator +(VectorULong v, ulong s) => BinOpS(v, s, (a, b) => a + b);

    public static VectorULong operator -(VectorULong v1, VectorULong v2) => BinOp(v1, v2, (a, b) => a - b);
    public static VectorULong operator -(VectorULong v, ulong s) => BinOpS(v, s, (a, b) => a - b);

    public static VectorULong operator *(VectorULong v1, VectorULong v2) => BinOp(v1, v2, (a, b) => a * b);
    public static VectorULong operator *(VectorULong v, ulong s) => BinOpS(v, s, (a, b) => a * b);

    public static VectorULong operator /(VectorULong v1, VectorULong v2) => BinOp(v1, v2, (a, b) => b != 0 ? a / b : 0);
    public static VectorULong operator /(VectorULong v, ulong s) => BinOpS(v, s, (a, b) => b != 0 ? a / b : 0);

    public static VectorULong operator %(VectorULong v1, VectorULong v2) => BinOp(v1, v2, (a, b) => b != 0 ? a % b : 0);
    public static VectorULong operator %(VectorULong v, ulong s) => BinOpS(v, s, (a, b) => b != 0 ? a % b : 0);

    public static VectorULong operator |(VectorULong v1, VectorULong v2) => BinOp(v1, v2, (a, b) => a | b);
    public static VectorULong operator |(VectorULong v, ulong s) => BinOpS(v, s, (a, b) => a | b);

    public static VectorULong operator ^(VectorULong v1, VectorULong v2) => BinOp(v1, v2, (a, b) => a ^ b);
    public static VectorULong operator ^(VectorULong v, ulong s) => BinOpS(v, s, (a, b) => a ^ b);

    public static VectorULong operator &(VectorULong v1, VectorULong v2) => BinOp(v1, v2, (a, b) => a & b);
    public static VectorULong operator &(VectorULong v, ulong s) => BinOpS(v, s, (a, b) => a & b);

    public static VectorULong operator >>(VectorULong v1, int shift) => BinOpS(v1, 0, (a, b) => a >> shift);
    public static VectorULong operator <<(VectorULong v1, int shift) => BinOpS(v1, 0, (a, b) => a << shift);

    public static bool operator ==(VectorULong v1, VectorULong v2)
    {
        if (ReferenceEquals(v1, null) || ReferenceEquals(v2, null)) return ReferenceEquals(v1, v2);
        if (v1.size != v2.size) return false;
        for (uint i = 0; i < v1.size; i++) if (v1.IntArray[i] != v2.IntArray[i]) return false;
        return true;
    }

    public static bool operator !=(VectorULong v1, VectorULong v2) => !(v1 == v2);

    public static bool operator >(VectorULong v1, VectorULong v2)
    {
        uint maxSize = Math.Min(v1.size, v2.size);
        for (uint i = 0; i < maxSize; i++) if (v1.IntArray[i] <= v2.IntArray[i]) return false;
        return true;
    }

    public static bool operator <(VectorULong v1, VectorULong v2)
    {
        uint maxSize = Math.Min(v1.size, v2.size);
        for (uint i = 0; i < maxSize; i++) if (v1.IntArray[i] >= v2.IntArray[i]) return false;
        return true;
    }

    public static bool operator >=(VectorULong v1, VectorULong v2)
    {
        uint maxSize = Math.Min(v1.size, v2.size);
        for (uint i = 0; i < maxSize; i++) if (v1.IntArray[i] < v2.IntArray[i]) return false;
        return true;
    }

    public static bool operator <=(VectorULong v1, VectorULong v2)
    {
        uint maxSize = Math.Min(v1.size, v2.size);
        for (uint i = 0; i < maxSize; i++) if (v1.IntArray[i] > v2.IntArray[i]) return false;
        return true;
    }

    public override bool Equals(object obj) => obj is VectorULong v && this == v;
    public override int GetHashCode() => IntArray?.GetHashCode() ?? 0;
}

class Program
{
    static void Main()
    {
        VectorULong vector = new VectorULong(5, 10);
        vector.Output();
    }
}
