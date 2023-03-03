#include <bits/stdc++.h> 
int construction(int N, string S)
{
	// Write your code here.
	set<char>s;

	for(int i=0; i<N; i++){

		s.insert(S[i]);
	}

	return s.size();
}
