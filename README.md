# 42-philosophers

42-philosophers project is a 42 Wolfsburg introduction to multi-threaded programming. It represents a typical
dining philosophers problem. For more information read subject.

## Usage

After cloning the repository, navigate to the philo/ directory.

```sh
make
./philo number_of_philosophers time_to_die time_to_sleep time_to_eat [number_of_meals]
```

Optional argument number_of_meals represents a way to limit the number of execution cycles. If all of the 
philosophers have eaten at least number_of_meals times, the simulation will end. Otherwise simulation will
end if one of the philosophers die.
