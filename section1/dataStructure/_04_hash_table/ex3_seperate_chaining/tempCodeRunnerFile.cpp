hashTable hashTable1;

  char command;

  while( command != 'e' ) {
    cin >> command;

    if ( command == 'a' ) {
      int key;
      string value;

      cin >> key;
      cin >> value;

      hashTable1.insert( key, value );
    }

    if ( command == 's' ) {
      int key;
      cin >> key;

      hashTable1.find( key );
    }
    
    if ( command == 'p' ) {
      hashTable1.display();
    }
  }