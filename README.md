# **Car Catalogue Program**

A C++ console application for storing, editing, validating, saving, and loading a catalogue of vehicles using a doubly linked list combined with a vector mirror for easy indexing.

## Features
### Catalogue Management

- Add new vehicles
- Edit existing vehicles
- Remove vehicles
- View full catalogue
- View single vehicle

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
