# **Car Catalogue Program**

A C++ console application for storing, editing, validating, saving, and loading a catalogue of vehicles using a doubly linked list combined with a vector mirror for easy indexing.

NOTE: this is currently a console application (Pics below), but I'm currently building a GUI for this program.

<img width="362" height="791" alt="carCatalogue2" src="https://github.com/user-attachments/assets/3cae8712-32c3-480c-8af9-1d73c5170b62" /> <img width="454" height="282" alt="carCatalogueSave" src="https://github.com/user-attachments/assets/563a1a0d-a99e-435a-b948-58b1f3251dcc" /> <img width="536" height="823" alt="carCatalogueLoading" src="https://github.com/user-attachments/assets/e0c46457-1261-4d93-b069-ecd4f36bf2f2" />




## Features
### Catalogue Management

- Add new vehicles
- Edit existing vehicles
- Remove vehicles
- View full catalogue
- View single vehicle
- Move vehicle location in the linked list order

### Data Structure

- Doubly linked list for in-memory ordering
- Vector mirror for quick access & loading
- Automatic index rebuilding after any modification

### Saving & Loading

- Saves catalogue to `CarCatalogue.txt`

- Loads catalogue automatically on startup

- Pipe-delimited format (no external libraries required)

### Input Validation

- `getInt()` — safe integer input

- `getDouble()` — safe double input

- `getYN()` — safe yes/no input

- `getVIN()` — fully validated 17-character VIN

- - VIN validation disallows:
     - I, O, Q
     - Non-alphanumeric characters
     - Any VIN not exactly 17 characters

## Project Structure
```
Car-Catalogue[

  /headers[
      CarCatHeaders.h
      Cars.h
      CatFunc.h
      UsePuts.h
      Savld.h
      ValIndex.h

  ]
  
  /source[

      Car-Catalogue1.cpp[
          - main()
     ]

      CatFunc.cpp[
          - addCar()
          - repCar()
          - editCar()
          - deleteCar()
          - moveCar()
     ]

      UsePuts.cpp[
          - optionsMenu()
          - printCatalogue()
          - printCar()
          - findCar()
     ]

      Savld.cpp[
          - saveCatalogue()
          - loadCatalogue()
     ]

      ValIndex.cpp[
          - IndexUpdate()
          - getInt()
          - getDouble()
          - getYN()
          - isValidVin()
          - getVIN()
     ]

  ]
]
```

## How the Program Works

1. On start, it attempts to load `CarCatalogue.txt`.

2. The main menu is displayed with options to:
   - Print the catalogue
   - View a specific car
   - Add a car
   - Edit a car
   - Delete a car
   - Save manually
   - Exit the program

3. All modifications update both:
   
   - The linked list
   - The vector
   - And re-index the entire catalogue using `indexUpdate()`

## Building

### Compile with:

     g++ -std=c++17 Car-Catalogue1.cpp CatFunc.cpp UsePuts.cpp Savld.cpp ValIndex.cpp -o CarCatalogue

Or use your IDE’s build system.

## Future Improvements
- Full input validation integration (ongoing)
- Index reassignment menu (instead of manual editing)
- Optional CSV/JSON import/export
- Sorting by price, mileage, or owner
- Switch from manual memory management → smart pointers (`std::unique_ptr`)
- Replace linked list with `std::list`

## License
This project is for learning purposes and has no specific license unless added later.
