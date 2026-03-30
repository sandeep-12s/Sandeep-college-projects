from geopy.distance import geodesic as GD

from geopy.geocoders import Nominatim              # Nominatim geocoder from the geopy library.



CLASS_RATE_PER_KM = {
    'sleeper': 0.72,
    'ac': 1.23
}

print("=== Railway Fare Calculator ===")

origin = input("\nEnter Origin Station: ").lower()

destination = input("\nEnter Destination Station: ").lower()

if origin == destination:
    print("Origin and destination cannot be the same")
    exit()
    
    
geolocator = Nominatim(user_agent="distance_app")    #  Find the coordinates of the origin and destination stations using geopy's Nominatim geocoder

loc1 = geolocator.geocode(origin)                    #  Finds the latitude and longitude of the starting place.
loc2 = geolocator.geocode(destination)               #  Finds the latitude and longitude of the destination place.


if loc1 and loc2:
    distance = GD((loc1.latitude, loc1.longitude), (loc2.latitude, loc2.longitude)).km  #  Calculates the geographical distance between two coordinates.
    print(f"Distance between {origin} and {destination} is {distance:.2f} km")          #  Prints the distance between the two stations in kilometers.

try:

    age = int(input("Passenger age: "))
    if age < 0:
        print("Age cannot be negative")
        exit()

    travel_class = input("Class (sleeper/ac): ").lower()
    if travel_class not in CLASS_RATE_PER_KM:
        print("Invalid class")
        exit()

    rate = CLASS_RATE_PER_KM[travel_class]

    base_fare = rate * distance

    if age <= 5:
        total_fare = 0
    elif age <= 12:
        total_fare = base_fare * 0.5
    elif age <= 59:
        total_fare = base_fare
    else:
        total_fare = base_fare * 0.75

    print("\n------ Ticket Summary ------")
    print("From:", origin)
    print("To:", destination)
    print("Distance:", distance, "km")
    print("Class:", travel_class)
    print("Total Fare: ₹", round(total_fare))

except ValueError:
    print("Invalid input entered")