*This project has been created as part of the 42 curriculum by jkralice.*

# Lib42
## Description
Lib42 is a highly opiniated, general use library, made in compliance with the 42 Norm. (norminette)

It is intended for my personal use, but it's avilable to anyone, should they ask for a copy.

The two main selling points of the library are:

**Arena allocator** - The entire library is build around it and expects the user's code to be as well. (At least when using the library's features.) For the benefits of arenas, check  out the talk by Ryan Fleury mentioned in the Resources section.

**Code generation** - The 42 Norm prohibits the use of functional macros and most of the C preprocessor in general. For this reason the library is fitted with shell scripts that act as code generators for the various data containers included in the library. The generators try to maintain complience with the 42 Norm, however the type definitions are decided by the user and so it is the user's responsibility to create typedefs that start with 't_' and don't push the generated code above 80 characters per line. Otherwise the generator handles the 42 Header and function prototype padding alignment automatically. Checking with norminette is highly recommended.

## Modules
### Data containers
#### Doubly-linked list (_dlist)
A type agnostic implementation of a doubly linked list.

It comes equipped with numerous functions to handle almost all use cases, with the only notable gap being a sorting function. This is a deliberate tradeoff for type agnosticity and it's left up to the user to implement.

Since freeing individual nodes of the list isn't possible with an arena allocator, _dlist implements a node reuse optimization:
- When removing a node using any of the _dlist_remove* functions, the node isn't forgotten but moved behind the end of the list. (except for _dlist_remove_front() which moves the node in front of the list's start.)
- When adding a new node after previously removing one, the _dlist_add* functions first check if a node exists after the end of the list, (or before the front in case of _dlist_add_front()) and reuses it, defaulting to allocating a new node when needed.

The only other impactful optimization concerns the indexing family of functions. They automatically select the shorter side to walk the list from to get to the desired node.

It is entirely possible to use _dlist as is, however doing so is type unsafe and prone to bugs. It is greatly recommended to generate a new list for each data type. See how in the Instructions section.

### Pipeline
**`!!!TODO!!!`**

## Instructions
### Compiling
The library is built via a Makefile, that implements all of the standard make targets required by the 42 Norm.
- Build with `make`, `make lib42.a` or `make debug` to include the flags `-g -fsanitize=leak,address,origin`.
- Clean up with `make clean`, `make fclean` if you want to also delete lib42.a and `make clean_gen` to delete generated code.

Unfortunatelly due to complience with the 42 Norm, all generated source files need to be manually pasted into the Makefile. The generator makes this easier by printing the generated file into stdout.

### Generating code
You can generate a type safe data container from any of the underlying, type agnostic container implementations by running the generate.sh script included within the container's directory.

The script will tell you how to use it itself when ran with 0 (or any incorrect number of) arguments. E.g.:
```
> ./list/generate
Usage: ./list/generate.sh type list_type list_prefix node_type node_prefix [headers...]

Where:
	type 			: Data type of the list.
	list_type		: Typedef of the generated list.
	list_prefix		: Prefix of the generated list functions. (Also the file names and header protector!)
	node_type		: Typedef of the generated node.
	node_prefix		: Prefix of the generated node functions.
	[headers...]	: Optional header includes. (Paths are relative to /list/!)
```

## Opinions
### Arena allocator
Arena allocators are simply better for everything. You can disagree all you want but you didn't write this library, I did.
The number of reasons why is in the hundreds so I'll only list the two most relevant:
- Asymetric allocations: Every malloc requires a free, this locks you into an object oriented style of programming, even tho you're not in an OO language and introduces the problem of having to keep track of every pointer returned by malloc. With arenas, you can do as many allocations as you desire, even overwriting the same pointer should you not need it anymore, the allocations all get free'd at once, regardless of if they're reachable or not.
- Lifetimes: Every malloc allocation has it's own lifetime, which doesn't correlate with the usage of the memory, or even with other allocations used within the same module/funciton/block, one has to constantly reason about each and every lifetime and whether it's their responsibility to end it. The lifetime of arena allocated memory is inherently tied to it's purpose, and no matter how many allocations you have, there will only ever be as many lifetimes as you yourself decide to create, they're not forced on you by the allocator. This is both easier to program with and reason about.

### NULL checking
None of the functions within the library NULL check their inputs, nor do they check if the arena allocator returned NULL.\
The reasoning is:
- This is NOT a library for mission critical software!!!
- Inputs aren't NULL checked because it's often possible that the user can guarantee a value to never be NULL, in those cases an extra check would hinder performance. It is therefore the user's responsibility to check that a value isn't NULL before giving it to a Lib42 function if they cannot guarantee it.
- The arena allocator's return value depends entirely on whether it has enough memory or not, which is (ideally) decided at the start of the program. When the allocator returns NULL, it can only mean one of two things: 1. Your use case requires more memory. 2. You messed up somewhere else in the program and ran out. Either way the issue is already present and the NULL return value is simply it's consequence. You may arrive to the conclusion then, that simply crashing the program from the arena itself when it runs out of memory would be more debug friendly. And you'd be right of course. Why doesn't it do that then? Simple: exit() isn't permitted in most

Should your program crash because of a NULL dereference, run it with the debug build of lib42.a and check where the NULL dereference happens. If it's inside the one of library's functions, it can only be one of the two issues mentioned above.

## Resources
All of the code was written manually by me, with AI assistance in the brainstorming and testing phase.\
\
Ideas for the arena allocaor were sourced from [Ryan Fleury's conference talk](https://www.youtube.com/watch?v=TZ5a3gCCZYo) about arenas and lifetimes.\
A lot of inspiration was taken from the various videos and talks of [Eskil Steenberg](https://www.quelsolaar.com/about/index.html), whom I greatly admire as a programmer.
