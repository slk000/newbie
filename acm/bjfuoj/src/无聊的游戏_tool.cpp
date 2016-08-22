#include <iostream>
using namespace std;
int main(int argc, char const *argv[])
{
	int n;
	int O=0,J=0;
	cin >> n;
	/*
	int number[n+1];

	for (int i = 1; i <= n; ++i)
	{
		number[i] = i;
	}

	cout << "k ";
	for (int i = 2; i <= n; ++i)
	{
		cout << number[i] << " ";
	}
	cout << endl;
*/
	cout<< "K2: ";

	for (int i = 1; i <= n; ++i)
	{	
		
		for (int j = i; j <= n; ++j)
		{
			if(j == i)continue;
			if ((i+j)%2) J++;
			else O++;
		}
	}
	cout << J << " " << O << endl;
	J = O = 0;
	cout << "K3: ";

	for (int i = 1; i <= n; ++i)
	{	
		
		for (int j = i; j <= n; ++j)
		{
			if(j == i)continue;
			for (int k = j; k <=n ; ++k)
			{
				if(k == j)continue;
				if ((i+j+k)%2) J++;
				else O++;
			}
		}
	}
	cout << J << " " << O << endl;

	J = O = 0;
	cout << "K4: ";

	for (int i = 1; i <= n; ++i)
	{	
		
		for (int j = i; j <= n; ++j)
		{
			if(j == i)continue;
			for (int k = j; k <=n ; ++k)
			{
				if(k == j)continue;
				for (int a = k; a <= n; ++a)
				{
					if(a == k)continue;
					if ((i+j+k+a)%2) J++;
					else O++;
					//cout << i << j << k << a << endl;
				}
			}
		}
	}
	cout << J << " " << O << endl;



	J = O = 0;
	cout << "K5: ";

	for (int i = 1; i <= n; ++i)
	{	
		
		for (int j = i; j <= n; ++j)
		{
			if(j == i)continue;
			for (int k = j; k <=n ; ++k)
			{
				if(k == j)continue;
				for (int a = k; a <= n; ++a)
				{
					if(a == k)continue;
					for (int b = a; b <= n; ++b)
					{
						if(b == a ) continue;
						if ((i+j+k+a+b)%2) J++;
						else O++;
					//cout << i << j << k << a << endl;
					}
				}
			}
		}
	}
	cout << J << " " << O <<endl;


	J = O = 0;
	cout << "K6: ";

	for (int i = 1; i <= n; ++i)
	{	
		
		for (int j = i; j <= n; ++j)
		{
			if(j == i)continue;
			for (int k = j; k <=n ; ++k)
			{
				if(k == j)continue;
				for (int a = k; a <= n; ++a)
				{
					if(a == k)continue;
					for (int b = a; b <= n; ++b)
					{
						if(b == a ) continue;
						for (int c = b; c <= n; ++c)
						{
							if(c == b)continue;
							if ((i+j+k+a+b+c)%2) J++;
							else O++;
							//cout << i << j << k << a << endl;
						}
						
					}
				}
			}
		}
	}
	cout << J << " " << O <<endl;


	J = O = 0;
	cout << "K7: ";

	for (int i = 1; i <= n; ++i)
	{	
		
		for (int j = i; j <= n; ++j)
		{
			if(j == i)continue;
			for (int k = j; k <=n ; ++k)
			{
				if(k == j)continue;
				for (int a = k; a <= n; ++a)
				{
					if(a == k)continue;
					for (int b = a; b <= n; ++b)
					{
						if(b == a ) continue;
						for (int c = b; c <= n; ++c)
						{
							if(c == b)continue;
							for (int d = c; d <= n; ++d)
							{
								if( d == c)continue;
								if ((i+j+k+a+b+c+d)%2) J++;
								else O++;
							
							}

						}
						
					}
				}
			}
		}
	}
	cout << J << " " << O <<endl;


	J = O = 0;
	cout << "K8: ";

	for (int i = 1; i <= n; ++i)
	{	
		
		for (int j = i; j <= n; ++j)
		{
			if(j == i)continue;
			for (int k = j; k <=n ; ++k)
			{
				if(k == j)continue;
				for (int a = k; a <= n; ++a)
				{
					if(a == k)continue;
					for (int b = a; b <= n; ++b)
					{
						if(b == a ) continue;
						for (int c = b; c <= n; ++c)
						{
							if(c == b)continue;
							for (int d = c; d <= n; ++d)
							{
								if( d == c)continue;
								for (int e = d; e <= n; ++e)
								{
									if(e == d)continue;
									if ((i+j+k+a+b+c+d+e)%2) J++;
									else O++;
								}

							
							}

						}
						
					}
				}
			}
		}
	}
	cout << J << " " << O <<endl;



	J = O = 0;
	cout << "K9: ";

	for (int i = 1; i <= n; ++i)
	{	
		
		for (int j = i; j <= n; ++j)
		{
			if(j == i)continue;
			for (int k = j; k <=n ; ++k)
			{
				if(k == j)continue;
				for (int a = k; a <= n; ++a)
				{
					if(a == k)continue;
					for (int b = a; b <= n; ++b)
					{
						if(b == a ) continue;
						for (int c = b; c <= n; ++c)
						{
							if(c == b)continue;
							for (int d = c; d <= n; ++d)
							{
								if( d == c)continue;
								for (int e = d; e <= n; ++e)
								{
									if(e == d)continue;
									for (int f = e; f <= n; ++f)
									{
										if(f == e)continue;
										if ((i+j+k+a+b+c+d+e+f)%2) J++;
										else O++;
									}
									
								}

							
							}

						}
						
					}
				}
			}
		}
	}
	cout << J << " " << O <<endl;

	J = O = 0;
	cout << "K10: ";

	for (int i = 1; i <= n; ++i)
	{	
		
		for (int j = i; j <= n; ++j)
		{
			if(j == i)continue;
			for (int k = j; k <=n ; ++k)
			{
				if(k == j)continue;
				for (int a = k; a <= n; ++a)
				{
					if(a == k)continue;
					for (int b = a; b <= n; ++b)
					{
						if(b == a ) continue;
						for (int c = b; c <= n; ++c)
						{
							if(c == b)continue;
							for (int d = c; d <= n; ++d)
							{
								if( d == c)continue;
								for (int e = d; e <= n; ++e)
								{
									if(e == d)continue;
									for (int f = e; f <= n; ++f)
									{
										if(f == e)continue;
										for (int g = f; g <= n; ++g)
										{
											if( g == f)continue;
											if ((i+j+k+a+b+c+d+e+f+g)%2) J++;
											else O++;
										}
	
									}
									
								}

							
							}

						}
						
					}
				}
			}
		}
	}
	cout << J << " " << O <<endl;

	return 0;
}