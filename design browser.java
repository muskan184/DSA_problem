class Node {
    String data;
    Node next;
    Node back;

    // Default constructor
    Node() {
        this.data = "";
        this.next = null;
        this.back = null;
    }

    // Constructor with one parameter
    Node(String data) {
        this.data = data;
        this.next = null;
        this.back = null;
    }

    // Constructor with multiple parameters
    Node(String data, Node next, Node back) {
        this.data = data;
        this.next = next;
        this.back = back;
    }
}

class BrowserHistory {
    Node currentPage;

    // Constructor for BrowserHistory
    BrowserHistory(String homepage) {
        currentPage = new Node(homepage);
    }

    // Method to visit a new URL
    public void visit(String url) {
        Node newNode = new Node(url);
        currentPage.next = newNode;
        newNode.back = currentPage;
        currentPage = newNode;
    }

    // Method to go back in history
    public String back(int steps) {
        while (steps > 0 && currentPage.back != null) {
            currentPage = currentPage.back;
            steps--;
        }
        return currentPage.data;
    }

    // Method to go forward in history
    public String forward(int steps) {
        while (steps > 0 && currentPage.next != null) {
            currentPage = currentPage.next;
            steps--;
        }
        return currentPage.data;
    }
}
