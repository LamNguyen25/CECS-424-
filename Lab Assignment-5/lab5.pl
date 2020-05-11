% lab assignment 5 - UFO sightings puzzle
% Lam Nguyen

% Flying Objects in the neighborhood
object('Balloon').
object('Clothesline').
object('Frisbee').
object('Water Tower').

% Day each person saw a UFO
day(3).
day(4).
day(5).
day(6).

solve :- object(BarradaObject), object(GortObject), object(KlatuObject), object(NiktoObject),
        all_diff([BarradaObject, GortObject, KlatuObject, NiktoObject]),
        
        day(BarradaDay), day(GortDay), day(KlatuDay), day(NiktoDay),
        all_diff([BarradaDay, GortDay, KlatuDay, NiktoDay]),
    
        Combine = [ ['Ms. Barrada', BarradaObject, BarradaDay],
                    ['Ms. Gort', GortObject, GortDay],
                    ['Mr. Klatu', KlatuObject, KlatuDay],
                    ['Mr. Nikto', NiktoObject, NiktoDay] ],
    
        % - Mr. Klatu made his sighting at some point earlier in the week than the one who saw the balloon,
        % but at some point later in the week than the one who spotted the frisbee (who isnt Ms. Gort).
        clue(Combine, [_, 'Balloon', BalloonDay]),
        clue(Combine, [_, 'Frisbee', FrisBeeDay]),
        before(KlatuDay, BalloonDay),
        after(KlatuDay, FrisBeeDay),
        \+ member(['Ms. Gort', 'Frisbee', _], Combine),
      
    
        % - Fridays sighting was made by either Ms. Barrada or the one who saw a clothesline (or both).
        ( member(['Ms. Barrada', _, 6], Combine);
          member([_, 'Clothesline', 6], Combine);
        % both
          member(['Ms. Barrada', 'Clothesline', 6], Combine) ),
    
        % - Mr. Nikto did not make his sighting on Tuesday.
        \+ member(['Mr. Nikto', _, 3], Combine),
    
        % - Mr. Klatu is not the one whose object turned out to be a water tower.
        \+ member(['Mr. Klatu', 'Water Tower', _], Combine),
    
        tell('Ms. Barrada', BarradaObject, BarradaDay),
        tell('Ms. Gort', GortObject, GortDay),
        tell('Mr. Klatu', KlatuObject, KlatuDay),
        tell('Mr. Nikto', NiktoObject, NiktoDay).


        % Predicate functions for ordering the days
        before(X, Y) :- X < Y.
        after(X, Y) :- X > Y.
        
        % clue function for 'Combine' data structure
        clue([X|_], X).
        clue([_|T], X) :- clue(T, X).

        % Succeeds if all elements of the argument list are bound and different.
        % Fails if any elements are unbound or equal to some other element.
        all_diff([H | T]) :- member(H, T), !, fail.
        all_diff([_ | T]) :- all_diff(T).
        all_diff([_]).

        % function to display the output
        tell(X, Y, Z) :-
        write(X),
        write(' saw a '),
        write(Y),
        write(' on '),
        ( Z =:= 3 ->
            write('Tuesday');
          Z =:= 4 ->
            write('Wednesday');
          Z =:= 5 ->
            write('Thursday');
          Z =:= 6 ->
            write('Friday') )
            , nl.

