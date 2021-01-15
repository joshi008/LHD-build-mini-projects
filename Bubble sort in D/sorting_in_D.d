void main()
{
    import std.datetime.stopwatch : benchmark;
    import std.math, std.parallelism, std.stdio;
	
	auto arr = [8,2,4,8,2,3,5,1,6];
		
	foreach(i, ref elem; arr)
		foreach(j, ref selem; arr)
			if(arr[i]>arr[j] && i<j)
			{
				auto temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
			}
			
	foreach(i, ref elem; arr)
		writefln("%d",arr[i]);

}

