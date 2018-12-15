for (int i = 0; i < roots.size(); ++i) {
if (roots[i] == nullptr) {
std::cerr << "n ";
}
else {
roots[i]->debug();
}
}
std::cerr << std::endl;