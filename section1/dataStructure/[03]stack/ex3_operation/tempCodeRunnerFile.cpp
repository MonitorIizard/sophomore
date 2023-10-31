while ( true ) {
        char operation;
        cin >> operation;

        if ( operation == 'U' ) {
            int data;
            cin >> data;
            add( data );
        }

        if ( operation == 'O' ) {
            pop( ); 
        }

        if ( operation == 'X' ) {
            break;
        }

        if ( operation == 'T' ) {
            peek( );
        }

        if ( operation == 'P' ) {
            displayAll( );
        }

        if ( operation == 'N' ) {
            cout << findLength( );
        }

    }