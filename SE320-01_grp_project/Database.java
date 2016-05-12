package groceries;

import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.Statement;
import java.sql.ResultSet;
import java.sql.SQLException;

/**
 * @author melms
 *
 */
public class Database {
    Connection con = null;
    Statement sm = null;
    String[] roles = {"undefined", "giver", "driver", "getter"};

    /**
     * 
     */
    Database() {
        try {
            Class.forName("*******************");
            con = DriverManager.getConnection("*********************************", "********", "*********");
            sm = con.createStatement();
        } catch (ClassNotFoundException e) {
            System.out.print("Error: Driver not found");
        } catch (SQLException e) {
            System.out.print("Error: Host not found");
        }
    }

    /**
     * 
     */
    public void createTables() {
        try {
            sm.addBatch("DROP TABLE IF EXISTS users");
            sm.addBatch("DROP TABLE IF EXISTS donations");
            sm.addBatch("CREATE TABLE donations (id INT PRIMARY KEY AUTO_INCREMENT NOT NULL, weight DOUBLE, type INT, logDate VARCHAR(50), expDate VARCHAR(50), giverID INT)");
            sm.addBatch("CREATE TABLE users (id INT PRIMARY KEY AUTO_INCREMENT NOT NULL, role INT, email VARCHAR(40), first VARCHAR(25), last varchar(25), phone VARCHAR(20), password VARCHAR(30), driversLicense VARCHAR(7), employerID VARCHAR(50))");
            sm.executeBatch();
        } catch (SQLException e) {
            System.out.println("ERROR: Failed to create tables");
        }
    }

    /**
     * @param role
     * @param email
     * @param first
     * @param last
     * @param phone
     * @param password
     * @param password2
     * @return
     */
    public boolean register(int role, String email, String first, String last, String phone, String password, String password2) {
        if (!email.equals("") && !first.equals("") && !last.equals("") && !phone.equals("") && !password.equals("") && !password2.equals("")) {
            if (password.equals(password2)) {
                try {
                    ResultSet rs = sm.executeQuery("SELECT * FROM users WHERE email='"+email+"'");
                    if (!rs.next()) {
                        sm.executeUpdate("INSERT INTO users VALUES (null, "+role+", '"+email+"', '"+first+"', '"+last+"', '"+phone+"', '"+password+"', '', '')");
                    } else {
                        System.out.println("ERROR: Email already exists");
                        return false;
                    }
                    rs.close();
                    return true;
                } catch (SQLException e) {
                    System.out.println("ERROR: SQL error");
                }
            } else {
                System.out.println("ERROR: Passwords do not match");
            }
        }
        return false;
    }

    /**
     * @param id
     * @param data
     * @return
     */
    public boolean completeRegistration(int id, String data) {
        try {
            ResultSet rs = sm.executeQuery("SELECT role FROM users WHERE id='"+id+"'");
            if (rs.next()) {
                int role = rs.getInt("role");
                if (role == 1 || role == 3) {
                    sm.executeUpdate("UPDATE users SET employerID='"+data+"' WHERE id="+id);
                } else if (role == 2) {
                    sm.executeUpdate("UPDATE users SET driversLicense='"+data+"' WHERE id="+id);
                }
                rs.close();
                return true;
            }
            rs.close();
        } catch (SQLException e) {
            System.out.println("ERROR: SQL error");
        }
        return false;
    }

    /**
     * @param email
     * @param password
     * @return
     */
    public String login(String email, String password) {
        try {
            ResultSet rs = sm.executeQuery("SELECT id FROM users WHERE email='"+email+"' AND password='"+password+"'");
            if (rs.next()) {
                return String.format("%s", rs.getInt("id"));
            }
        } catch (SQLException e) {
            System.out.println("ERROR: SQL error");
        }
        return "-1";
    }

    /**
     * @return
     */
    public boolean showUsers() {
        try {
            ResultSet rs = sm.executeQuery("SELECT * FROM users ORDER BY role ASC");
            System.out.println();
            while (rs.next()) {
                Account a = new Account(rs.getInt("id"), roles[rs.getInt("role")], rs.getString("first"), rs.getString("last"), rs.getString("email"), rs.getString("phone"), rs.getString("driversLicense"), rs.getString("employerID"));
                System.out.println(a.toString());
            }
            rs.close();
            return true;
        } catch (SQLException e) {
            System.out.println("Error: Could not display students");
        }
        return false;
    }

    /**
     * @param delivery
     * @return
     */
    public boolean postDelivery(Delivery delivery) {
        if (delivery.totalWeight >= 10.0) {
            try {
                for (int i = 0; i < delivery.donations.size(); i++) {
                    Donation d = delivery.donations.get(i);
                    sm.addBatch("INSERT INTO donations VALUES (null, "+d.weight+", "+d.type+", '"+d.logDate+"', '"+d.expDate+"', "+d.giverID+")");
                }
                sm.executeBatch();
                return true;
            } catch (SQLException e) {
                System.out.println("Error: Could not post delivery");
            }
        }
        return false;
    }

    /**
     * @return
     */
    public boolean showDonations() {
        try {
            ResultSet rs = sm.executeQuery("SELECT * FROM donations");
            System.out.println();
            while (rs.next()) {
                Donation d = new Donation(rs.getDouble("weight"), rs.getInt("type"), rs.getString("logDate"), rs.getString("expDate"), rs.getInt("giverID"));
                System.out.println(d.toString());
            }
            rs.close();
            return true;
        } catch (SQLException e) {
            System.out.println("Error: Could not display donations");
        }
        return false;
    }

    /**
     * 
     */
    public void close() {
        try {
            sm.close();
            con.close();
        } catch (SQLException e) {
            System.out.print("Error: Could not close connection");
        }
    }
}
