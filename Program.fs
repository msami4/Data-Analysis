//
// F# program to analyze Divvy daily ride data.
//
// << Mohammed Sami >>
// U. of Illinois, Chicago
// CS 341, Spring 2019
// Project #04
//

#light

module project04

//
// ParseLine and ParseInput
//
// Given a sequence of strings representing Divvy data, 
// parses the strings and returns a list of lists.  Each
// sub-list denotes one bike ride.  Example:
//
//   [ [176;74;1252;21;595;1986;1]; ... ]
//
// The values are station id (from), station id (to), bike
// id, starting hour (0..23), trip duration (secs), birth
// year (0=>not specified), and gender (0=>not specified, 
// 1=>identifies as male, 2=>identifies as female).
//
let ParseLine (line:string) = 
  let tokens = line.Split(',')
  let ints = Array.map System.Int32.Parse tokens
  Array.toList ints

let rec ParseInput lines = 
  let rides = Seq.map ParseLine lines
  Seq.toList rides

let rec countGender x ridedata = 
    match ridedata with
    | [] -> 0
    | e::rest when (List.nth e 6)=x -> 1 + (countGender x rest)
    | _::rest          -> 0 + (countGender x rest)
 
let rec totalAge ridedata =
    match ridedata with
    | []      -> 0
    | e::rest when(List.nth e 5 <> 0) -> (System.DateTime.Now.Year-(List.nth e 5)) + totalAge rest
    | _::rest -> totalAge rest
    
let rec total30 ridedata =
    match ridedata with
    | []      -> 0
    | e::rest when((List.nth e 4) <= 30*60) -> 1 + total30 rest
    | _::rest -> total30 rest
    
let rec total60 ridedata =
    match ridedata with
    | []      -> 0
    | e::rest when((List.nth e 4) <= 60*60&&(List.nth e 4) > 30*60) -> 1 + total60 rest
    | _::rest -> total60 rest
    
let rec total120 ridedata =
    match ridedata with
    | []      -> 0
    | e::rest when((List.nth e 4) <= 120*60&&(List.nth e 4) > 60*60) -> 1 + total120 rest
    | _::rest -> total120 rest

let rec total2hr ridedata =
    match ridedata with
    | []      -> 0
    | e::rest when((List.nth e 4) > 120*60) -> 1 + total2hr rest
    | _::rest -> total2hr rest
    
let rec count0 ridedata =
    match ridedata with
    | [] -> 0
    | e::rest when(List.nth e 5 > 0)->1 + count0 rest
    | _::rest ->  count0 rest

let rec histo0 ridedata =
    match ridedata with
    | [] -> 0
    | e::rest when(List.nth e 3 = 0)->1 + histo0 rest
    | _::rest ->  histo0 rest

let rec histo1 ridedata =
    match ridedata with
    | [] -> 0
    | e::rest when(List.nth e 3 = 1)->1 + histo1 rest
    | _::rest ->  histo1 rest
    
let rec histo2 ridedata =
    match ridedata with
    | [] -> 0
    | e::rest when(List.nth e 3 = 2)->1 + histo2 rest
    | _::rest ->  histo2 rest
    
    
let rec histo3 ridedata =
    match ridedata with
    | [] -> 0
    | e::rest when(List.nth e 3 = 3)->1 + histo3 rest
    | _::rest ->  histo3 rest
    
let rec histo4 ridedata =
    match ridedata with
    | [] -> 0
    | e::rest when(List.nth e 3 = 4)->1 + histo4 rest
    | _::rest ->  histo4 rest
    
let rec histo5 ridedata =
    match ridedata with
    | [] -> 0
    | e::rest when(List.nth e 3 = 5)->1 + histo5 rest
    | _::rest ->  histo5 rest
    
    
let rec histo6 ridedata =
    match ridedata with
    | [] -> 0
    | e::rest when(List.nth e 3 = 6)->1 + histo6 rest
    | _::rest ->  histo6 rest
    
let rec histo7 ridedata =
    match ridedata with
    | [] -> 0
    | e::rest when(List.nth e 3 = 7)->1 + histo7 rest
    | _::rest ->  histo7 rest
    
let rec histo8 ridedata =
    match ridedata with
    | [] -> 0
    | e::rest when(List.nth e 3 = 8)->1 + histo8 rest
    | _::rest ->  histo8 rest
    
    
let rec histo9 ridedata =
    match ridedata with
    | [] -> 0
    | e::rest when(List.nth e 3 = 9)->1 + histo9 rest
    | _::rest ->  histo9 rest

let rec histo10 ridedata =
    match ridedata with
    | [] -> 0
    | e::rest when(List.nth e 3 = 10)->1 + histo10 rest
    | _::rest ->  histo10 rest

let rec histo11 ridedata =
    match ridedata with
    | [] -> 0
    | e::rest when(List.nth e 3 = 11)->1 + histo11 rest
    | _::rest ->  histo11 rest
    
let rec histo12 ridedata =
    match ridedata with
    | [] -> 0
    | e::rest when(List.nth e 3 = 12)->1 + histo12 rest
    | _::rest ->  histo12 rest
    
    
let rec histo13 ridedata =
    match ridedata with
    | [] -> 0
    | e::rest when(List.nth e 3 = 13)->1 + histo13 rest
    | _::rest ->  histo13 rest
    
let rec histo14 ridedata =
    match ridedata with
    | [] -> 0
    | e::rest when(List.nth e 3 = 14)->1 + histo14 rest
    | _::rest ->  histo14 rest
    
let rec histo15 ridedata =
    match ridedata with
    | [] -> 0
    | e::rest when(List.nth e 3 = 15)->1 + histo15 rest
    | _::rest ->  histo15 rest
    
    
let rec histo16 ridedata =
    match ridedata with
    | [] -> 0
    | e::rest when(List.nth e 3 = 16)->1 + histo16 rest
    | _::rest ->  histo16 rest
    
let rec histo17 ridedata =
    match ridedata with
    | [] -> 0
    | e::rest when(List.nth e 3 = 17)->1 + histo17 rest
    | _::rest ->  histo17 rest
    
let rec histo18 ridedata =
    match ridedata with
    | [] -> 0
    | e::rest when(List.nth e 3 = 18)->1 + histo18 rest
    | _::rest ->  histo18 rest
    
    
let rec histo19 ridedata =
    match ridedata with
    | [] -> 0
    | e::rest when(List.nth e 3 = 19)->1 + histo19 rest
    | _::rest ->  histo19 rest
    
let rec histo20 ridedata =
    match ridedata with
    | [] -> 0
    | e::rest when(List.nth e 3 = 20)->1 + histo20 rest
    | _::rest ->  histo20 rest

let rec histo21 ridedata =
    match ridedata with
    | [] -> 0
    | e::rest when(List.nth e 3 = 21)->1 + histo21 rest
    | _::rest ->  histo21 rest
    
let rec histo22 ridedata =
    match ridedata with
    | [] -> 0
    | e::rest when(List.nth e 3 = 22)->1 + histo22 rest
    | _::rest ->  histo22 rest
        
let rec histo23 ridedata =
    match ridedata with
    | [] -> 0
    | e::rest when(List.nth e 3 = 23)->1 + histo23 rest
    | _::rest ->  histo23 rest
    
let rec printstars n = 
    match n with
    | 0 -> printf ""
    | 1 -> printf "*"
    | _ -> printf "*" 
           printstars (n-1)
           
let ifZero v n =
    if n=0 then 0.0
    else (float(v)/float(n))

[<EntryPoint>]
let main argv =
  //
  // input file name, then input divvy ride data and build
  // a list of lists:
  //
  printf "filename> "
  let filename = System.Console.ReadLine()
  let contents = System.IO.File.ReadLines(filename)
  let ridedata = ParseInput contents

  //printfn "%A" ridedata
  let N = List.length ridedata
  printfn ""
  printfn "# of riders: %A" N
  printfn ""
  
  
  let numMale = countGender 1 ridedata
  let percentMale = (float(numMale)/float(N)) *100.0
  printfn "%% of riders identifying as male: %A (%A%%)" (numMale)(percentMale) 
  
  let numFemale = countGender 2 ridedata
  let percentFemale = (float(numFemale)/float(N)) *100.0
  printfn "%% of riders identifying as female: %A (%A%%)" (numFemale)(percentFemale) 
  printfn ""
  
  let allAges = totalAge ridedata
  let aboveZero = count0 ridedata
  let percentAge = ifZero allAges aboveZero
  printfn "Average age: %A" percentAge
  printfn ""
  
  let riding30 = total30 ridedata
  let percent30 = (float(riding30)/float(N))*100.0
  let riding60 = total60 ridedata
  let percent60 = (float(riding60)/float(N))*100.0
  let riding120 = total120 ridedata
  let percent120 = (float(riding120)/float(N))*100.0
  let riding2hr = total2hr ridedata
  let percent2hr = (float(riding2hr)/float(N))*100.0
  printfn "** Ride Durations:"
  printfn " 0..30 mins: %A (%A%%)" (riding30)(percent30)
  printfn " 30..60 mins: %A (%A%%)" (riding60)(percent60)
  printfn " 60..120 mins: %A (%A%%)" (riding120)(percent120)
  printfn " > 2 hours: %A (%A%%)" (riding2hr)(percent2hr)
  printfn ""
  
  let num0 = histo0 ridedata 
  let num1 = histo1 ridedata
  let num2 = histo2 ridedata
  let num3 = histo3 ridedata
  let num4 = histo4 ridedata
  let num5 = histo5 ridedata
  let num6 = histo6 ridedata
  let num7 = histo7 ridedata
  let num8 = histo8 ridedata
  let num9 = histo9 ridedata
  let num10 =histo10 ridedata
  let num11 =histo11 ridedata
  let num12 =histo12 ridedata
  let num13 =histo13 ridedata
  let num14 =histo14 ridedata
  let num15 =histo15 ridedata
  let num16 =histo16 ridedata
  let num17 =histo17 ridedata
  let num18 =histo18 ridedata
  let num19 =histo19 ridedata
  let num20 =histo20 ridedata
  let num21 =histo21 ridedata
  let num22 =histo22 ridedata
  let num23 =histo23 ridedata
  
  printfn "** Ride Start Time Histogram:"
  
  printf " 0: "
  printstars (num0/10)
  printf "%A" num0
  printfn ""
  
  printf " 1: "
  printstars (num1/10)
  printf "%A" num1
  printfn ""
  
  printf " 2: "
  printstars (num2/10)
  printf "%A" num2
  printfn ""
  
  printf " 3: "
  printstars (num3/10)
  printf "%A" num3
  printfn ""
  
  printf " 4: "
  printstars (num4/10)
  printf "%A" num4
  printfn ""
  
  printf " 5: "
  printstars (num5/10)
  printf "%A" num5
  printfn ""
  
  printf " 6: "
  printstars (num6/10)
  printf "%A" num6
  printfn ""
  
  printf " 7: "
  printstars (num7/10)
  printf "%A" num7
  printfn ""
  
  printf " 8: "
  printstars (num8/10)
  printf "%A" num8
  printfn ""
  
  printf " 9: "
  printstars (num9/10)
  printf "%A" num9
  printfn ""
  
  printf " 10: "
  printstars (num10/10)
  printf "%A" num10
  printfn ""
  
  printf " 11: "
  printstars (num11/10)
  printf "%A" num11
  printfn ""
  
  printf " 12: "
  printstars (num12/10)
  printf "%A" num12
  printfn ""
  
  printf " 13: "
  printstars (num13/10)
  printf "%A" num13
  printfn ""
  
  printf " 14: "
  printstars (num14/10)
  printf "%A" num14
  printfn ""
  
  printf " 15: "
  printstars (num15/10)
  printf "%A" num15
  printfn ""
  
  printf " 16: "
  printstars (num16/10)
  printf "%A" num16
  printfn ""
  
  printf " 17: "
  printstars (num17/10)
  printf "%A" num17
  printfn ""
  
  printf " 18: "
  printstars (num18/10)
  printf "%A" num18
  printfn ""
  
  printf " 19: "
  printstars (num19/10)
  printf "%A" num19
  printfn ""
  
  printf " 20: "
  printstars (num20/10)
  printf "%A" num20
  printfn ""
  
  printf " 21: "
  printstars (num21/10)
  printf "%A" num21
  printfn ""
  
  printf " 22: "
  printstars (num22/10)
  printf "%A" num22
  printfn ""
  
  printf " 23: "
  printstars (num23/10)
  printf "%A" num23
  printfn ""
  
  0
