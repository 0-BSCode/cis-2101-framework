# Philosophy
- Deliberate practice
- Focus on implementation, not coming up with testing

# File Structure
- main.c contains all test cases (call all functions)
- Modules contains all versions of each implementation
- Each implementation can have multiple versions (your practice)
- Having one file call every implementation can let you test new implementations
    - e.g. Call implementation-1-v1 -> make sure it works -> re-implement w/ v2 -> compare w/ v1 (if output is different, v2 isn't correct)
