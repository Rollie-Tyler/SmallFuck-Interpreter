using System;
using System.Collections.Generic;

class Program {
	
	static void Main(string[] args) {
		string program = "*>*>*>*>*><<<<<*[>*][*<]";
		bool[] dataBand = new bool[10/*2048*/];
		Stack<int> bracketOpen = new Stack<int>();
		uint index = 0;

		for(int i = 0; i < program.Length && index < dataBand.Length; i++)
		{
			char c = program[i];
			switch(c)
			{
				case '>':
					//Console.WriteLine("> ");
					if(index < (uint)(dataBand.Length - 1))
						index++;
					else
						index = 0;
					break;
				case '<':
					//Console.WriteLine("< ");
					if(index > 0)
						index--;
					else
						index = (uint)(dataBand.Length - 1);
					break;
				case '*':
					//Console.WriteLine("* ");
					if(dataBand[index] == true)
						dataBand[index] = false;
					else
						dataBand[index] = true;
					break;
				case '[':
					//Console.WriteLine("[ i={0}", i);
					//if(!dataBand[index])
						bracketOpen.Push(i);
					break;
				case ']':
					//Console.WriteLine("] i={0}", index);
					if(bracketOpen.Count > 0)
						if(!dataBand[index/*bracketOpen.Peek()-1*/])
							i = bracketOpen.Pop() - 1;
					break;
				case ' ':
				default:
					break;
			}

			foreach(bool b in dataBand)
			{
				Console.Write("{0} ", b?"1":"0");
			}
			Console.WriteLine();
			for(int k = 0; k < dataBand.Length; k++)
			{
				if(k == index)
					Console.Write("^ ");
				else
					Console.Write("  ");
			}
			Console.WriteLine();
		}		
	}
}
