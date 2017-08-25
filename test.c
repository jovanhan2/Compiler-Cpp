int f (int a ) {
        int res;
        if ( a == 1 ) {
                return 1;
        }
        else {
                res = a + f( a - 1 );
        }

        return res;
}
