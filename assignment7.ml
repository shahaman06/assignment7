let mean lst =
  let total = List.fold_left (+.) 0.0 (List.map float_of_int lst) in
  total /. float_of_int (List.length lst)

let median lst =
  let sorted = List.sort compare lst in
  let len = List.length sorted in
  if len mod 2 = 1 then
    float_of_int (List.nth sorted (len / 2))
  else
    let mid1 = List.nth sorted (len / 2 - 1) in
    let mid2 = List.nth sorted (len / 2) in
    (float_of_int (mid1 + mid2)) /. 2.0

let mode lst =
  let tbl = Hashtbl.create 10 in
  List.iter (fun x ->
    Hashtbl.replace tbl x ((try Hashtbl.find tbl x with Not_found -> 0) + 1)
  ) lst;
  let max_freq = Hashtbl.fold (fun _ v acc -> max v acc) tbl 0 in
  Hashtbl.fold (fun k v acc -> if v = max_freq then k :: acc else acc) tbl []

let () =
  let data = [1; 2; 2; 3; 4] in
  Printf.printf "Mean: %.2f\n" (mean data);
  Printf.printf "Median: %.2f\n" (median data);
  Printf.printf "Mode: ";
  List.iter (Printf.printf "%d ") (mode data);
  Printf.printf "\n"
